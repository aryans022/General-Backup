import java.util.*;
import java.io.*;
import javax.sound.midi.*;

public class MiniMiniMusicApp {
	
	public void play() {
		try {
			
			Sequencer player =  MidiSystem.getSequencer();
			player.open();
			
			Sequence seq = new Sequence(Sequence.PPQ, 4);
			
			Track track = seq.createTrack();
			
			ShortMessage a = new ShortMessage();
			a.setMessage(144, 1, 44, 100);
			MidiEvent noteOn = new MidiEvent(a, 1);
			track.add(noteOn);
			
			ShortMessage b = new ShortMessage();
			b.setMessage(128, 1, 44, 100);
			MidiEvent noteOff = new MidiEvent(b, 16);
			track.add(noteOff);
			
			ShortMessage c = new ShortMessage();
			c.setMessage(144, 9, 30, 100);
			MidiEvent note1On = new MidiEvent(c, 1);
			track.add(note1On);
			
			ShortMessage d = new ShortMessage();
			d.setMessage(128, 9, 30, 100);
			MidiEvent note1Off = new MidiEvent(d, 48);
			track.add(note1Off);
			
			player.setSequence(seq);
			
			player.start();
			
		}
		catch (Exception ex) {
			ex.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		MiniMiniMusicApp mini = new MiniMiniMusicApp();
		mini.play();	
	}
}