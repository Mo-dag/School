import javax.swing.JPanel;
import java.awt.Graphics;
//Swing : är ett java bibliotek för att skapa grafiska användargränssnitt. 
//Swing : JFrame,JButton,JPanel.paintComponent(Graphics g) tillhör AWT.
public class View extends JPanel{
  // Vi skapa model för att View skulle kunna få tag på figurer.
  // Där i Main : 
  //Model m = new Model();
  //View v = new View(m); 
  private Model model; // Denna är en lokal model som befinner sig i View klass, vi skapar den för att vi ska dela till den 
  // model värde från main, där får den tag på Figurer. och vi skickar den från main genom konstruktorn för att den lokala kommer få värde.
  // Att båda refererar till samma Model-objekt.
  public View(Model model){
    this.model = model;
  }

// View ansvarar för att rita figurerna med paintComponent(Graphics g).
// Swing anropar paintComponent() när panelen behöver ritas om.

// Inuti paintComponent() använder vi en for-loop för att rita alla figurer.
// model.getNrFig() anger hur många gånger loopen ska köras.
// model.getFigur(i) hämtar figuren på aktuellt index.
// f.draw(g) ritar figuren med dess färg, position och storlek.
//
// Varje figur ritas i den ordning den lagrades i Model.
@Override 
  public void paintComponent(Graphics g) {
        // Rensar panelen innan figurerna ritas igen.
        //Super anropar föräldrar klassen JPanel. Den hjälper till att återställa ritytan. Därefter ritar vi alla obj som fortfarande finns kvar.
        super.paintComponent(g);
        //Swing anropar paintComponent när panelen ska ritas om.
        //Graphics g : är klassen som innehåller ritmetoder : fillRect, fillOval etc. g : referensvariable som pekar på Graphics obj.
        // Går igenom alla figurer som finns i Model.
        for (int i = 0; i < model.getNrFig(); i++) {

            // Hämtar figuren på index i.
            Figur f = model.getFigur(i);

            // Anropar rätt draw() genom polymorfism.
            f.draw(g);
        }
  }
}
