public class TestMyDate {

    public static void main(String[] args) {

        MyDate d1, d2;
        boolean testOK = true;

        // test 1: försöker hitta ett fel i konstruktorn

        try { // Försök skapa ett ogiltigt datum.
            new MyDate(2023, 2, 29); // Datumet ska inte kunna skapas.
            testOK = false; // Testet misslyckas om inget exception kastas.
        } catch (IllegalArgumentException e) { // Ett ogiltigt datum ska kasta detta exception.
        }

        if (testOK) {
            System.out.println("Test 1 OK.");
        } else {
            System.out.println("Test 1 failed.");
        }

        testOK = true;

        // test 2: försöker hitta ett fel i compareTo

        d1 = new MyDate(2020, 12, 31); // Skapa det tidigare datumet.
        d2 = new MyDate(2021, 1, 1); // Skapa det senare datumet.
        testOK = testOK && d1.compareTo(d2) < 0 && d2.compareTo(d1) > 0; // Kontrollera ordningen.

        if (testOK) {
            System.out.println("Test 2 OK.");
        } else {
            System.out.println("Test 2 failed.");
        }

        testOK = true;

        // test 3: försöker hitta ett fel i equals

        d1 = new MyDate(2024, 5, 17); // Skapa det första datumet.
        d2 = new MyDate(2024, 5, 17); // Skapa ett separat objekt med samma datum.
        testOK = testOK && d1.equals(d2); // Lika datum ska vara lika trots olika objekt.

        if (testOK) {
            System.out.println("Test 3 OK.");
        } else {
            System.out.println("Test 3 failed.");
        }

    }

}
