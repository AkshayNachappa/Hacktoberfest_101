//Traffic lights simulator

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class Traffic  {
	JFrame frame = new JFrame("Traffic");
	JButton red = new JButton();
	JButton yellow = new JButton();
	JButton green = new JButton();
	JRadioButton r = new JRadioButton("Red");
	JRadioButton y = new JRadioButton("Yellow");
	JRadioButton g = new JRadioButton("Green");
	ButtonGroup t = new ButtonGroup();
	Traffic(){
		red.setContentAreaFilled(false);
		yellow.setContentAreaFilled(false);
		green.setContentAreaFilled(false);

		red.setBounds(110,50,60,60);
		red.setBackground(Color.red);
		frame.add(red);

		yellow.setBounds(110,110,60,60);
		yellow.setBackground(Color.yellow);
		frame.add(yellow);

		green.setBounds(110,170,60,60);
		green.setBackground(Color.green);
		frame.add(green);

		r.setBounds(110,250,70,30);
		frame.add(r);
		r.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				red.setContentAreaFilled(true);
				yellow.setContentAreaFilled(false);
				green.setContentAreaFilled(false);
			}
		});

		y.setBounds(110,290,70,30);
		frame.add(y);
		y.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				red.setContentAreaFilled(false);
				yellow.setContentAreaFilled(true);
				green.setContentAreaFilled(false);
			}
		});

		g.setBounds(110,330,70,30);
		frame.add(g);
		g.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				red.setContentAreaFilled(false);
				yellow.setContentAreaFilled(false);
				green.setContentAreaFilled(true);
			}
		});
		
		t.add(r);
		t.add(y);
		t.add(g);
		frame.setSize(360,480);
		frame.getContentPane().setLayout(null);
		frame.getContentPane().setBackground(Color.black);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
    public static void main(String[] args){
		new Traffic();
    }
}
