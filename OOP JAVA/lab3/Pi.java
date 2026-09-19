public class Pi { // Deklarerar klassen Pi som beräknar ett närmevärde för pi.

    public static void main(String[] args) { // Huvudmetoden som körs när programmet startas.
        int decimalCount = 70; // Sätter standardantalet decimaler till 70 om inget argument anges.
        if (args.length > 0) { // Om användaren skickade ett argument, använd det istället.
            decimalCount = Integer.valueOf(args[0]); // Konverterar argumentet från text till int.
        }

        RatNum res = new RatNum(0, 1); // Startvärdet för summan är 0/1.
        RatNum sixteenth = new RatNum(1, 16); // Konstanten 1/16 används i pi-serien.

        for (int k = 0; k <= decimalCount; k++) { // Upprepar beräkningen för varje term i serien.
            RatNum power = sixteenth.pow(k); // Beräknar (1/16)^k.
            res = res.add(power.mul(new RatNum(4, 8 * k + 1))); // Lägger till 4/(8k+1) * (1/16)^k.
            res = res.sub(power.mul(new RatNum(2, 8 * k + 4))); // Subtraherar 2/(8k+4) * (1/16)^k.
            res = res.sub(power.mul(new RatNum(1, 8 * k + 5))); // Subtraherar 1/(8k+5) * (1/16)^k.
            res = res.sub(power.mul(new RatNum(1, 8 * k + 6))); // Subtraherar 1/(8k+6) * (1/16)^k.
        }

        RatNum m = new RatNum(1, 1); // Skapar 1 för att flytta decimaler.
        RatNum ten = new RatNum(10, 1); // Skapar talet 10 för att multiplicera med 10 upprepade gånger.
        for (int k = 0; k < decimalCount; k++) { // Upprepar så att vi får 10^decimalCount.
            m = m.mul(ten); // Multiplicerar m med 10 varje gång.
        }
        System.out.print("pi = "); // Skriver ut texten "pi = ".
        String intPart = res.toIntString(); // Hämtar heltalsdelen av pi-närmevärdet.
        System.out.print(intPart); // Skriver ut heltalsdelen.
        System.out.print("."); // Skriver ut decimalpunkt.
        RatNum digits = res.sub(RatNum.parse(intPart)); // Räknar ut decimaldelen genom att subtrahera heltalsdelen.
        System.out.print(digits.mul(m).toIntString()); // Multiplicerar decimaldelen med 10^n och skriver ut n decimaler.
        System.out.println("..."); // Skriver ut ellips för att visa att det fortsätter.
    }
}
