import java.io.*;
import javax.swing.*;
import java.awt.*;
import javax.sound.midi.*;

public class MiniMusicPlayer3 {
	
	static JFrame f = new JFrame("My first music video");
	static MyDrawPanel ml;
	
	class MyDrawPanel extends JPanel implements ControllerEventListener {
		
		boolean msg = false;
		
		public void controlChange (ShortMessage event) {
			msg = true;
			repaint();
		}
		
		public void paintComponent(Graphics g) {
			if (msg) {
				
				Graphics2D g2 = (Graphics2D) g;
				
				int r = (int)(Math.random()*250);
				int gr = (int)(Math.random()*250);
				int b = (int)(Math.random()*250);
				
				g.setColor(new Color(r, gr, b));
				
				int ht = (int)((Math.random()*100)+10);
				int wt = (int)((Math.random()*100)+10);
				int x = (int)((Math.random()*500));
				int y = (int)((Math.random()*500));
				
				g.fillRect(x, y, ht, wt);
				msg = false;
			}
		}
	}
	
	public static MidiEvent makeEvent(int comd, int chan, int note, int vol, int beat) {
		
		MidiEvent event = null;
		
		try {
			ShortMessage a = new ShortMessage();
			a.setMessage(comd, chan, note, vol);
			event = new MidiEvent(a, beat);
		}
		catch(Exception ex) {
		}
		
		return event;
	}
	
	public static void main(String[] args) {
		MiniMusicPlayer3 mini = new MiniMusicPlayer3();
		mini.go();
	}
	
	public void setUpGui() {
		ml = new MyDrawPanel();
		f.setContentPane(ml);
		f.setBounds(30,30, 600,600);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	} 
	
	public void go() {
		
		setUpGui();
		
		try {
			
			Sequencer sequencer = MidiSystem.getSequencer();
			sequencer.open();
			
			int[] eventsIWant = {127};
			sequencer.addControllerEventListener(ml, eventsIWant);
			
			Sequence seq = new Sequence(Sequence.PPQ, 4);
			Track track = seq.createTrack();
			
			for (int i = 0; i < 61; i++) {
				track.add(makeEvent(176, 1, 127, 0, i));							//controller event
				track.add(makeEvent(144, 1, i+30, 100, i));							//note on
				track.add(makeEvent(128, 1, i+30, 100, i+5));						//note off
			}
			
			sequencer.setSequence(seq);
			sequencer.setTempoInBPM(80);
			sequencer.start();
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
	}
	
}