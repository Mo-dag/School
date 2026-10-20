/*
 * Figur är en abstrakt klass som innehåller gemensamma egenskaper
 * för alla figurer: x, y, width, height och color.
 *
 * Konstruktorn initierar objektets instansvariabler med de värden
 * som skickas in när objektet skapas med new.
 *
 * Getters används för att läsa dessa värden.
 * Eftersom getters är instansmetoder läser de värden från
 * just det objekt som metoderna anropas på.
 *
 * Exempel:
 * a.getX() hämtar x från objektet a.
 * b.getX() hämtar x från objektet b.
 *
 * Inuti getX() syftar this.x på det aktuella objektets x.
 * Därför behöver vi inte skicka objektet som parameter.
 */
import java.awt.*;
import java.io.Serializable;

// Gemensamma egenskaper för alla figurer
public abstract class Figur implements Serializable {
    //Vi använder serialisering när Java sparar eller läser in obj från andra filer.
    private static final long serialVersionUID = 1L;

    private int x, y, width, height;
    private Color color;

    public Figur(int x, int y, int width, int height, Color color) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.color = color;
    }

    // Varje figur bestämmer själv hur den ska ritas
    public abstract void draw(Graphics g);

    public int getX() { return x; }
    public int getY() { return y; }
    public int getWidth() { return width; }
    public int getHeight() { return height; }
    public Color getColor() { return color; }
}

/*
             Figur (abstract)
                   │
          ┌────────┼────────┐
          ↓        ↓        ↓
      Rektangel   Oval     Prick
          │        │        │
          └────────┼────────┘
                   ↓
            ArrayList<Figur>
                   │
                 Model
*/
// Vi deklarerar en abstract metod, varför ? för att när vi skapar en referensvariable av typ Figur, ska java 
// Vet att typen Figur erbjuder den metoden. 
// och senare : Figur f = new Oval(); 
// f.draw();
//Java kontrollerar att Figur deklarerar draw(), men kör Oval klassens implementation.

