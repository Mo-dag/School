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
  public void addFig(Figur f){
    figurer.add(f);
  }
  public void undo(){
    // ArrayList är en klass. Denna klass har många funktioner. remove,add,get,set(gammal,ny),clear,size och isEmpty som returnerar boolean.
    
    if(!figurer.isEmpty()){
      figurer.remove(figurer.size() -1);
    }
  }
}
