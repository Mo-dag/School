
import javax.swing.JPanel;
import java.awt.Graphics;

public class View extends JPanel {

    // Referens till Model där alla figurer finns sparade
    private Model model;

    // Tillfällig figur som visas medan musen dras
    private Figur preview;

    public View(Model model) {
        this.model = model;
    }

    // Tar emot en tillfällig figur från Controller
    public void setPreview(Figur f) {
        preview = f;
        repaint();
    }

    @Override
    public void paintComponent(Graphics g) {

        // Rensar panelen innan figurerna ritas igen
        super.paintComponent(g);

        // Går igenom alla figurer som finns sparade i Model
        for (int i = 0; i < model.getNrFig(); i++) {

            // Hämtar figuren på index i
            Figur f = model.getFigur(i);

            // Anropar rätt draw-metod genom polymorfism
            f.draw(g);
        }

        // Ritar den tillfälliga figuren om den finns
        if (preview != null) {
            preview.draw(g);
        }
    }
}
