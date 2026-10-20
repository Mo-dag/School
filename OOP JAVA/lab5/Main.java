import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        // Skapar Model, View och Controller
        Model model = new Model();
        View view = new View(model);
        Controller controller = new Controller(model, view);

        // Delar upp fönstret i knappar, rityta och statusrad
        JFrame frame = new JFrame("Ritprogram");
        frame.setLayout(new BorderLayout());
        frame.add(controller.skapaKnappar(), BorderLayout.NORTH);
        frame.add(view, BorderLayout.CENTER);
        frame.add(controller.getStatus(), BorderLayout.SOUTH);

        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
