import java.awt.Color;

public abstract class Figur{
  private int x,y,width,height;
  private Color color;

  public Figur(int x,int y,int width,int height,Color color){
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
    this.color = color;
  }
  // Vi ska lägga en metod som subklasserna : (Cirkel, Rektangel) ska implementera.
  public abstract void draw(Graphics g){
    
  }
  // Vi skapa getters för att låta View läsa värde från privata variabler : x,y,width,height,color
  public int getX(){return x;}
  public int getY(){return y;
  public int getWidth(){return width;}
  public int getHeight(){return height;}
  public int getColor(){return color;}
  
}
