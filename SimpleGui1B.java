import java.util.*;					
import java.io.*;													//not needed
import javax.swing.*;												//main important packages
import java.awt.event.*;											//main important packages

public class SimpleGui1B implements ActionListener {
	
	JButton button;
	
	public static void main(String[] args) {
		
		SimpleGui1B gui = new SimpleGui1B();
		gui.go();
		
	}
	
	public void go() {
		
		JFrame frame = new JFrame();
		button = new JButton("click me");		
		
		button.addActionListener(this);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(button);
		frame.setSize(300, 300);
		frame.setVisible(true);
		
	}
	
	public void actionPerformed(ActionEvent event) {
		button.setText("You clicked me");
	}
}