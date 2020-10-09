import javax.sound.midi.*;

public class MiniMusicPlayer2 implements ControllerEventListener {

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
		MiniMusicPlayer2 mini = new MiniMusicPlayer2();
		mini.go();
	}
	
	public void go() {
		
		try {
			
			Sequencer sequencer = MidiSystem.getSequencer();
			sequencer.open();
			
			int[] eventsIWant = {127};
			sequencer.addControllerEventListener(this, eventsIWant);
			
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
	
	public void controlChange(ShortMessage event) {
		System.out.print("la");
	}
	
}