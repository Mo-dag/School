

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

  
    public static parse(String s){
        
    }
}
