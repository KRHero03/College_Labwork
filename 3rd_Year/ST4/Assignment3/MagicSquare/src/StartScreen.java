
//Usually you will require both swing and awt packages
// even if you are working with just swings.
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class StartScreen {
    private int n = 3;
    private JFrame frame;
    private JPanel panel;
    private JLabel label;
    private JTextField tf;
    private JButton btn;
    public StartScreen() {

        frame = new JFrame("Magic Square");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 100);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);

        panel = new JPanel();

        label = new JLabel("Enter N:");
        tf = new JTextField(n+"",10);
        btn = new JButton("Set N");
        
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent evt) {
                try{
                    n = Integer.parseInt(tf.getText());
                    if(n<1 || n>20) throw new Exception("Please enter N between 1 and 20!");
                    MainScreen ms = new MainScreen(n);
                    frame.dispose();
                }catch(Exception e){
                    System.out.println(e);
                    JOptionPane.showMessageDialog(frame,e.getMessage(),"Magic Square - Error",JOptionPane.ERROR_MESSAGE);
                }
            }

            
        });

        panel.add(label);
        panel.add(tf);
        panel.add(btn);

        frame.getContentPane().add(BorderLayout.CENTER,panel);
        frame.setVisible(true);

    }
    
}