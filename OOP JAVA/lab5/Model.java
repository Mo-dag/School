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

public class Model{
  private ArrayList <Figur> figurer = new ArrayList<>();
  // Vi skpar en ArrayList som lagrar figurobjelt.
  // Oval, Prick och Rektangel ärver från figur.
  // addFigur() används för att lägga till dessa objekt i listan, den gör det möjligt för andra klasser att lägga
  // till figurer utan att komma åt den privata listan direkt
  public void addFigur(Figur f){
    figurer.add(f);
  }  
}
