

public class RatNum{

    private int n;
    private int t;

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

    public RatNum(){
        this.n=1;
        this.t=0;
    }
    public RatNum(int t){
        this.t = t;
        this.n = 1;
    }

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
    public RatNum(RatNum x){
        this.n = x.n;
        this.t = x.t;
    }
    public int getNumerator(){
        return this.t;
    }
    public int getDenominator(){
        return this.n;
    }

    public String toString(){
        return t + "/"+n;
    }

  // Klass metod (static) kan inte använda instansvariabler direkt(instansvariabler : private int n; private int t;)
  // Reason : tillhörighet.
  //DVS klass metoden : parse(), tillhör klassen.  
  // Instansvariabler tillhör objekt. 
    // med andra ord : är den static metod, kan man inte använda : this.instansvariable;
  
    public static RatNum parse(String s){
        //Korrigerat: Så en klassmetod kan inte läsa eller ändra instansvariabler direkt. 
        //Klassmetoden tillhör klassen, medan instansvariablerna tillhör objekt.
        // Vårt problem här är att vi ska skapa en metod som tar en String,
        // kontrollerar den och sedan returnerar ett nytt rationellt tal med det godkända värdet.
        // Det enda rationella talet här är alltså ett objekt av klassen RatNum, eller? 
        //Eftersom ett rationellt tal representeras av två int-värden.


        //För att kontorllera om värdet är giltig, vi skulle filtrera värdena och spara de i int array. 
        // För att värdena är sträng typ och finns det / med de. 
        // Vi kommer att använda split. split() är en funk av klassen String.
        // Den delar Java sträng 

        String[] newS = s.split("/");
        // Villkoret är : om n = 0 »» fel // om n inte finns »» n = 1;
        int n;
        int t;
        if(newS.length == 1){n = 1;}
        else{
            n = Integer.parseInt(newS[1]);
        }
        t = Integer.parseInt(newS[0]);

        if(n == 0){throw new NumberFormatException("Error");}
        // Vi filtrerade värdena och omvandlade de till int.
        // För att spara värdena i instansvariabler anropar vi
        // RatNum som vi skapade innan, den är inte static och kan använda this.t , this.n
        // Men för att den är inte static, den tillhör Obj. Då : vi behöver skapa ett nytt obj. new.
        return new RatNum(t,n);
    }
    // Nu : De vill att vi återanvänder logiken i parse() i stället för att skriva samma kontrollkod igen.
     public RatNum(String s){
        //RatNum obj = new RatNum(parse(s)); DETTA ÄR FEEEEEEEEEEEL !!!!
        //Problemet är att parse() returnerar en referens, inte själva objektet.
        //Vi behöver en bro som tar värdena n och t »»
        // från objektet som referensen pekar på och kopierar dem till det nya objektet.
        this(parse(s));
        // This : letar efter en konstruktor som tar emot referenser som parse producerar.

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
    }
        // equals måste skrivas med exakt rätt parameter för att fungerar.
    //Så vi vill ändra den och skapa vår egen equals()
    // för att kunna jämföra två olika objekt utifrån deras innehåll
    // inte bara två referenser som pekar på samma objekt
    @Override    // Ersätter javas gamla equals.
    public boolean equals(Object obj){
        // Är obj inte ett RatNum ? "Vi använder instansof : Java-keyword ✅ "
        if(!(obj instanceof RatNum)){
            return false;
        }
        //if(this.getClass() != obj.getClass) ← ← ← Detta är lärarens sätt att skriva villkoret. 
        //if(!(obj instansof RatNum)          ← ← ← Vår sätt. Både gör samma sak.

        
        // obj redan pekar på ett RatNum obj.
        // obj »» typ Object
        // vi skulle skapa en ny referensvariable av typen RatNum för att få värde i den korrekta typen
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
    public boolean lessThan(RatNum r){

        if ((this.t*r.n)<(r.t*this.n)){
            return true;
        }
        return false;

        // return this.t * r.n < r.t * this.n;
    }
    // För att addera två olika RatTal, skulle vi ha en gemensam nämnare.
    // a * d + c * b / b*d
    public RatNum add(RatNum r){
        RatNum sum = new RatNum();
        sum.t = (this.t * r.n) + (this.n * r.t);
        sum.n = this.n * r.n;
        return new RatNum(sum.t,sum.n);
    }
    public RatNum sub(RatNum r){
        RatNum sum = new RatNum();
        sum.t = (this.t*r.n) - (this.n*r.t);
        sum.n = this.n * r.n;
        return new RatNum(sum.t,sum.n);
    }
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

    public RatNum div(RatNum r){
        RatNum sum = new RatNum();
        sum.t = this.t * r.n;
        sum.n = this.n * r.t;

        return new RatNum(sum.t,sum.n);
    }
    public String toIntString(){
        int tal = this.t/this.n;
        return Integer.toString(tal);
    }
}
