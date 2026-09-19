import java.math.BigInteger; // Importerar Java-klassen BigInteger för heltal utan storleksgräns.

public class RatNum { // Deklarerar klassen RatNum som representerar rationella tal.
    private BigInteger n; // Lagrar nämnaren som ett BigInteger-objekt.
    private BigInteger t; // Lagrar täljaren som ett BigInteger-objekt.

    public static int gcd(int n, int t) { // Räknar ut största gemensamma delare för två int-värden.
        if (n == 0 && t == 0) { // Om båda är noll finns ingen giltig gcd.
            throw new IllegalArgumentException("gcd(0, 0) is undefined"); // Kastar ett fel som signalerar ogiltigt värde.
        }
        return BigInteger.valueOf(n).gcd(BigInteger.valueOf(t)).intValue(); // Gör om int till BigInteger och beräknar gcd, sedan tillbaka till int.
    }

    private RatNum(BigInteger t, BigInteger n) { // Privat konstruktor som skapar ett reducerat bråk från BigInteger-värden.
        if (n.signum() == 0) { // Om nämnaren är 0 är bråket ogiltigt.
            throw new NumberFormatException("Denominator = 0"); // Kastar fel om nämnaren är noll.
        }
        if (n.signum() < 0) { // Om nämnaren är negativ, flyttar minustecknet till täljaren.
            t = t.negate(); // Byter tecken på täljaren.
            n = n.negate(); // Byter tecken på nämnaren.
        }
        BigInteger divisor = t.gcd(n); // Beräknar största gemensamma delare mellan täljare och nämnare.
        this.t = t.divide(divisor); // Dividerar täljaren med gcd för att förenkla.
        this.n = n.divide(divisor); // Dividerar nämnaren med gcd för att förenkla.
    }

    public RatNum() { // Konstruktor som skapar 0 som rationellt tal.
        this(BigInteger.ZERO, BigInteger.ONE); // Skickar in 0/1 till den privata konstruktionen.
    }

    public RatNum(int t) { // Konstruktor som gör ett heltal till ett rationellt tal.
        this(BigInteger.valueOf(t), BigInteger.ONE); // Gör int till BigInteger och skapar t/1.
    }

    public RatNum(int t, int n) { // Konstruktor för att skapa bråk från två int-värden.
        this(BigInteger.valueOf(t), BigInteger.valueOf(n)); // Gör om till BigInteger och använd den privata konstruktionen.
    }

    public RatNum(RatNum x) { // Kopieringskonstruktor som kopierar ett annat RatNum-objekt.
        this.t = x.t; // Kopierar täljaren från x.
        this.n = x.n; // Kopierar nämnaren från x.
    }

    public int getNumerator() { // Returnerar täljaren som int.
        return t.intValue(); // Konverterar BigInteger till int.
    }

    public int getDenominator() { // Returnerar nämnaren som int.
        return n.intValue(); // Konverterar BigInteger till int.
    }

    @Override // Markerar att vi överskrider Object.toString().
    public String toString() { // Returnerar bråket som text, exempel: "3/4".
        return t + "/" + n; // Sammansätter täljare och nämnare till en sträng.
    }

    public static RatNum parse(String s) { // Tolkar en textsträng som ett rationellt tal.
        String[] parts = s.split("/", -1); // Delar strängen vid /, även om det finns tomma delar.
        if (parts.length > 2 || parts[0].isEmpty() || (parts.length == 2 && parts[1].isEmpty())) { // Kontrollerar att formen är giltig.
            throw new NumberFormatException("Invalid rational number"); // Kastar fel om strängen inte är ett giltigt bråk.
        }
        BigInteger numerator = new BigInteger(parts[0]); // Skapar BigInteger från täljaren.
        BigInteger denominator = parts.length == 1 ? BigInteger.ONE : new BigInteger(parts[1]); // Sätter nämnare till 1 om ingen nämnare anges.
        return new RatNum(numerator, denominator); // Returnerar ett nytt reducerat RatNum-objekt.
    }

    public RatNum(String s) { // Konstruktor som bygger RatNum från en sträng.
        this(parse(s)); // Anropar parse() och kopieringskonstruktorn.
    }

    @Override // Överskrider equals() från Object.
    public boolean equals(Object obj) { // Jämför om två RatNum-objekt har samma värde.
        if (!(obj instanceof RatNum)) { // Om obj inte är RatNum, är de inte lika.
            return false; // Returnerar false.
        }
        RatNum r = (RatNum) obj; // Castar objektet till RatNum.
        return t.equals(r.t) && n.equals(r.n); // Jämför täljare och nämnare.
    }

    @Override // Överskrider hashCode() från Object.
    public int hashCode() { // Skapar ett hashvärde för RatNum-objektet.
        return 31 * t.hashCode() + n.hashCode(); // Kombinerar hashkoden för täljare och nämnare.
    }

    public boolean lessThan(RatNum r) { // Jämför om detta tal är mindre än ett annat.
        return t.multiply(r.n).compareTo(r.t.multiply(n)) < 0; // Jämför korsprodukter a*d < c*b.
    }

    public RatNum add(RatNum r) { // Adderar två rationella tal.
        return new RatNum(t.multiply(r.n).add(n.multiply(r.t)), n.multiply(r.n)); // Beräknar (a*d + c*b)/(b*d).
    }

    public RatNum sub(RatNum r) { // Subtraherar två rationella tal.
        return new RatNum(t.multiply(r.n).subtract(n.multiply(r.t)), n.multiply(r.n)); // Beräknar (a*d - c*b)/(b*d).
    }

    public RatNum mul(RatNum r) { // Multiplicerar två rationella tal.
        return new RatNum(t.multiply(r.t), n.multiply(r.n)); // Beräknar (a*c)/(b*d).
    }

    public RatNum div(RatNum r) { // Dividerar två rationella tal.
        return new RatNum(t.multiply(r.n), n.multiply(r.t)); // Beräknar (a*d)/(b*c).
    }

    public RatNum pow(int k) { // Upphöjer ett rationellt tal till potens k.
        if (k < 0) { // Om exponenten är negativ, byter vi plats på täljare och nämnare.
            return new RatNum(n.pow(-k), t.pow(-k)); // Beräknar (n/t)^(-k) = (t/n)^k .
        }
        return new RatNum(t.pow(k), n.pow(k)); // Beräknar (t/n)^k genom att upphöja båda till k.
    }

    public String toIntString() { // Returnerar heltalsdelen av bråket som text.
        return t.divide(n).toString(); // Delar täljaren med nämnaren och konverterar till string.
    }
}
