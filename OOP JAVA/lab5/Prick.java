import java.awt.*;

//Prick ärver alla gemensamma egenskaper från Figur. DVS : x,y,width,height,Color);

public class Prick extends Figur{
  //Konstruktorn tar emot pricken's x, y osv
  public Prick(int x,int y,int width,int height,Color color){
    //Anropar Figur konstruktorn genom Super().
    super(x,y,width,height,color);
  }
  @Override
  public void draw(Graphics g){
    //Hämtar objektets färg via getColor(), och använda denna färg som Graphics ska rita med.
    g.setColor(getColor());
    //Getters hämtar värden från just denna obj. draw anrops genom obj, för att den tillhör obj.
    g.fillOval(getX(),getY(),5,5);
  }
}
