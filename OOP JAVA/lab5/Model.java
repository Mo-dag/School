/*STACK                   HEAP
┌─────────┐        ┌──────────────────┐
│ model ──┼───────→│ Model-objekt     │
└─────────┘        │                  │
                   │ figurer ─────────┼───┐
                   └──────────────────┘   │
                                          ▼
                                    ┌───────────┐
                                    │ ArrayList │
                                    │ [ ]       │
                                    └───────────┘*/

import java.io.*;
import java.util.ArrayList;

public class Model implements Serializable {
    private static final long serialVersionUID = 1L;

    // Alla figurer som finns på ritytan
    private ArrayList<Figur> figurer = new ArrayList<>();

    public void addFigur(Figur f) {
        figurer.add(f);
    }

    public void undo() {
        if (!figurer.isEmpty()) {
            figurer.remove(figurer.size() - 1);
        }
    }

    public Figur getFigur(int index) {
        return figurer.get(index);
    }

    public int getNrFig() {
        return figurer.size();
    }

    // Skriver hela ritningen till en fil
    public void save(String filnamn) throws IOException {
        try (ObjectOutputStream ut = new ObjectOutputStream(new FileOutputStream(filnamn))) {
            ut.writeObject(this);
        }
    }

    // Läser in figurerna i samma Model-objekt som View använder
    public void load(String filnamn) throws IOException, ClassNotFoundException {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(filnamn))) {
            Object objekt = in.readObject();
            if (!(objekt instanceof Model)) {
                throw new IOException("Filen innehåller ingen ritning.");
            }

            Model sparad = (Model) objekt;
            if (sparad.figurer == null) {
                throw new IOException("Ritningen innehåller ingen figurlista.");
            }

            // Vi byter listan, inte själva Model-objektet
            figurer = sparad.figurer;
        }
    }
}
