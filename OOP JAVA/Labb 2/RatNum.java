
//Alla kommentarer som börjar med två stjärnor är JavaDoc Kommentarer.
// De används för att skriva documentation. Den dokumentara klassens publika gränssnitt.
/** A class that represents Rational Numbers.
 * A rational number consists of two integers.
 * @author Mo Dagher and Akram Abdi
 * Version 0.1
 */
public class RatNum{

    private int n;
    private int t;
// Den första meningen i doc berättar vad metoden tillför.
    /**
     * Return the greatest common divisor of two integers.
     * @param n the denominator (nämnaren)
     * @param t the numerator   (täljaren)
     * @return the greatest common divisor.
     * @throws IllegalArgumentException if both n and t are zero.
     */
    static public int gcd(int n,int t){



        int GCD = 1;
        int loop = 1;
        if(n==0 && t ==0){
            throw new IllegalArgumentException("Error 404");
        }
        int smallest = Math.max(n,t);
        while(loop<=Math.abs(smallest)){
            if(n % loop == 0 && t % loop ==0){
                GCD=loop;
            }
            loop++;
        }
        return GCD;

    }
    //En konstruktör har ingen returtyp. Den konstruerar/initierar objektet.
    /**
     * Constructs a rational number representing zero.
     */
    public RatNum(){
        this.n=1;
        this.t=0;
    }

    /**
     * Constructs a rational number representing the value of t
     * @param t the numerator
     */
    public RatNum(int t){
        this.t = t;
        this.n = 1;
    }

    /**
     * Constructs a rational number in reduced form with numerator t and denominator n.
     * @param t the numerator
     * @param n the denominator
     * @throws NumberFormatException if the denominator is zero.
     */
    //↓↓↓↓↓↓↓↓↓↓↓ En konstruktör som fyller en obj. Måste ; new RatNum(värde,värde) →→→→→ RatNum obj = new RatNum(värde, värde);
    public RatNum(int t,int n){
        if(n == 0){throw new NumberFormatException("Denominator = 0");}
        int delare = gcd(n,t);
        if(n<0){
            n *= -1;
            t*= -1;
        }
        this.n = n/delare;
        this.t = t/delare;
    }

    /**
     * Constructs a rational number as a copy of another RatNum obj.
     * @param x is the RatNum objekt to copy.
     */
    public RatNum(RatNum x){
        this.n = x.n;
        this.t = x.t;

        //new RatNum(a)
        //↓
        //skapar nytt objekt
        //↓
        //RatNum(RatNum x) körs
        //↓
        //kopierar x.n och x.t

    }

    /**
     * Returns the numerator.
     * @return the numerator value.
     */
    public int getNumerator(){
        return this.t;
    }

    /**
     * Return the denominator
     * @return the denominator value.
     */

    public int getDenominator(){
        return this.n;
    }

    /**
     * Returns this rational number as a string.
     * @return the numerator and denominator as text.
     */
    public String toString(){
        return t + "/"+n;
    }

    /**
     * Take a rational number from a string and returns it in reduced form as RatNum object.
     * @param s the string to parse.
     * @return RatNum object representing the rational number.
     * @throws NumberFormatException if the string is invalid or the denominator is Zero.
     */
    public static RatNum parse(String s) {
        int n;
        int t;
        String [] newS = s.split("/");
        if(newS.length == 1){n = 1;}
        else{
            n = Integer.parseInt(newS[1]);
        }
        t = Integer.parseInt(newS[0]);

        if(n == 0){throw new NumberFormatException("Error");}
        // Vi filtrerade värdena och omvandlade de till int.
        // För att spara värdena i instansvariabler anropar vi
        // RatNum som vi skapade innan, den är inte static och kan använda this.t , this.n
        // Men för att den är inte static, den tillhör Obj. Då : vi behöver skapa ett nytt obj.
        return new RatNum(t,n);
        // Parse skapar en separat RatNum obj
        // problemet att : RatNum obj : utan namn !!! Vår funk returnerar vad ?
        // Den returnerar REFERENS Referensen till det objektet.
        // Så parse() kan inte stå helt själv. Den returnerar en referens till ett RatNum-objekt. /
        // Vi måste ta emot den referensen om vi vill behålla de behandlade värdena.
    }

    /**
     * Constructs a rational number from a string.
     * @param s the string to parse.
     * @throws NumberFormatException if the string is invalid.
     */
    public RatNum(String s){
        //RatNum obj = new RatNum(parse(s)); Detta är fel !
        //Problemet är att parse() returnerar en referens, inte själva objektet.
        //Vi behöver en bro som tar värdena n och t »»
        // från objektet som referensen pekar på och kopierar dem till det nya objektet.
        this(parse(s));
        // This : letar efter en konstruktör som tar emot referenser som parse producerar.

        //parse("3/4")
        //↓
        //returnerar referens
        //        │
        //        ▼
        //   objekt A [t=3, n=4]
        //        │
        //        │ x pekar hit
        //        ▼
        //RatNum(RatNum x)
        //        │
        //        ├── this.t = x.t
        //        └── this.n = x.n
        //        ↓
        //   objekt B [t=3, n=4]

        /*
        Vi kunde skriva också : 
        RatNum temp = parse(s);
        this.n = temp.n;
        this.t = temp.t;
        */
    }

    /**
     * Checks if the rational number is equals to other rational number of the same type and return true or false.
     * @param obj the object to compare with
     * @return true if the objects represents the same rational number, otherwise false.
     */
    // equals måste skrivas med exakt rätt parameter för att fungerar.
    //Så vi vill ändra den och skapa vår egen equals()
    // för att kunna jämföra två olika objekt utifrån deras innehåll
    // inte bara två referenser som pekar på samma objekt
    @Override    // Ersätter javas gamla equals.
    public boolean equals(Object obj){
        // Är obj inte ett RatNum ? "Vi använder instanceof : Java-keyword ✅ "
        if(!(obj instanceof RatNum)){
            return false;
        }
        // obj redan pekar på ett RatNum obj.
        // obj »» typ Object
        // vi skulle skapa en ny referensvariabel av typen RatNum för att få värde i den korrekta typen
        // Vi castar obj till RatNum så att r kan använda RatNum:s fält och metoder.

        RatNum r = (RatNum) obj;

        return this.n == r.n && this.t == r.t;


        //obj
        //↓
        //är RatNum? ❌ → false
        //↓ ja
        //gör obj till RatNum r
        //↓
        //jämför t och n
        //↓
        //true / false

    }
    // För att jämföra två bråk utan att göra de till decimaler
    // Kommer vi att använda kors-multi
    // a/b < c/d ?
    // a * d < c * b ?

    /**
     * Checks whether this rational number is less than the given rational number.
     * @param r the rational number to compare with.
     * @return true if this rational number is less than r, otherwise false.
     */

    public boolean lessThan(RatNum r){

        if ((this.t*r.n)<(r.t*this.n)){
            return true;
        }
        return false;

        // return this.t * r.n < r.t * this.n;
    }

    /**
     * Adds the given rational number to this rational number.
     * @param r the given rational numebr to add.
     * @return a referens to a new RatNum object representing the sum.
     */

    // För att addera två olika RatTal, skulle vi ha en gemensam nämnare.
    // a * d + c * b / b*d
    public RatNum add(RatNum r){
        RatNum sum = new RatNum();
        sum.t = (this.t * r.n) + (this.n * r.t);
        sum.n = this.n * r.n;
        return new RatNum(sum.t,sum.n);
    }

    /** Subtract the given rational number from this rational number.
     *
     * @param r the given rational number to subtract.
     * @return a referens to a new RatNum obj representing the sum.
     */
    public RatNum sub(RatNum r){
        RatNum sum = new RatNum();
        sum.t = (this.t*r.n) - (this.n*r.t);
        sum.n = this.n * r.n;
        return new RatNum(sum.t,sum.n);
    }

    /**
     * Multiply a given RatNum with this rational number.
     * @param r the given rational number to multiply.
     * @return a referens to a new RatNum obj representing the sum.
     */
    public RatNum mul(RatNum r){
        RatNum sum = new RatNum();
        sum.n = this.n*r.n;
        sum.t = this.t*r.t;
        return new RatNum(sum.t,sum.n);
    }
    //a/b ÷ c/d
    //↓
    //a/b * d/c
    //↓
    //(a*d) / (b*c)


    /**
     * Divide a given rational number with this rational number
     * @param r the given rational number to divide.
     * @return a referens to a new RatNum obj representing the sum.
     */
    public RatNum div(RatNum r){
        RatNum sum = new RatNum();
        sum.t = this.t * r.n;
        sum.n = this.n * r.t;

        return new RatNum(sum.t,sum.n);
    }

    /**
     * Returns an integer number in form of string from this rational number.
     * @return the integer value of this rational number as a string.
     */
    public String toIntString(){
        int tal = this.t/this.n;
        return Integer.toString(tal);
    }

}
