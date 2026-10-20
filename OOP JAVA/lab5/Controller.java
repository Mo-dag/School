import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Controller extends MouseAdapter {

    // Referenser till Model och View
    private Model model;
    private View view;

    // Håller reda på vald figur och färg
    private String figurtyp = "Rektangel";
    private Color color = Color.BLACK;

    // Musens startposition
    private int startX, startY;

    // Texten längst ner i fönstret
    private JLabel status = new JLabel("Figur: Rektangel | Färg: Svart");

    public Controller(Model model, View view) {
        this.model = model;
        this.view = view;

        // Kopplar muslyssnarna till ritytan
        view.addMouseListener(this);
        view.addMouseMotionListener(this);
    }

    // Ändrar vald figur
    public void setFigurtyp(String typ) {
        figurtyp = typ;
        uppdateraStatus();
    }

    // Ändrar vald färg
    public void setColor(Color c) {
        color = c;
        uppdateraStatus();
    }

    // Uppdaterar texten som visar figur och färg
    private void uppdateraStatus() {
        String namn = "Svart";

        if (color.equals(Color.RED)) {
            namn = "Röd";
        }
        else if (color.equals(Color.BLUE)) {
            namn = "Blå";
        }

        status.setText("Figur: " + figurtyp + " | Färg: " + namn);
    }

    // Main använder denna för att lägga status längst ner
    public JLabel getStatus() {
        return status;
    }

    // Skapar knapparna som ska finnas överst
    public JPanel skapaKnappar() {
        JPanel panel = new JPanel();

        String[] typer = {"Prick", "Rektangel", "Oval"};

        // Skapar en knapp för varje figurtyp
        for (String typ : typer) {
            JButton knapp = new JButton(typ);

            knapp.addActionListener(e -> setFigurtyp(typ));

            panel.add(knapp);
        }

        // Lägger till färgknapparna
        panel.add(fargKnapp("Svart", Color.BLACK));
        panel.add(fargKnapp("Röd", Color.RED));
        panel.add(fargKnapp("Blå", Color.BLUE));

        // Knapp för att ta bort senaste figuren
        JButton undoKnapp = new JButton("Undo");
        undoKnapp.addActionListener(e -> undo());

        panel.add(undoKnapp);

        return panel;
    }

    // Skapar en knapp som väljer en viss färg
    private JButton fargKnapp(String namn, Color c) {
        JButton knapp = new JButton(namn);

        knapp.addActionListener(e -> setColor(c));

        return knapp;
    }

    // Sparar var musen trycktes ner
    @Override
    public void mousePressed(MouseEvent e) {
        startX = e.getX();
        startY = e.getY();
    }

    // Skapar en figur utifrån musens koordinater
    private Figur skapaFigur(int slutX, int slutY) {

        // Minsta koordinaterna blir figurens startpunkt
        int x = Math.min(startX, slutX);
        int y = Math.min(startY, slutY);

        // Räknar ut bredd och höjd
        int width = Math.abs(slutX - startX);
        int height = Math.abs(slutY - startY);

        // Skapar den valda figuren
        if (figurtyp.equals("Rektangel")) {
            return new Rektangel(x, y, width, height, color);
        }
        else if (figurtyp.equals("Oval")) {
            return new Oval(x, y, width, height, color);
        }
        else if (figurtyp.equals("Prick")) {
            return new Prick(slutX, slutY, 5, 5, color);
        }

        return null;
    }

    // Visar figuren medan musen dras
    @Override
    public void mouseDragged(MouseEvent e) {
        Figur f = skapaFigur(e.getX(), e.getY());
        view.setPreview(f);
    }

    // Sparar figuren när musknappen släpps
    @Override
    public void mouseReleased(MouseEvent e) {
        Figur f = skapaFigur(e.getX(), e.getY());

        if (f != null) {
            model.addFigur(f);
        }

        // Tar bort förhandsvisningen
        view.setPreview(null);
    }

    // Tar bort den senaste figuren
    public void undo() {
        model.undo();
        view.repaint();
    }
}
