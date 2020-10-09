import javax.sound.midi.*;

public class MiniMusicPlayer1 {

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
		
		try {
			
			Sequencer sequencer = MidiSystem.getSequencer();
			sequencer.open();
			
			Sequence seq = new Sequence(Sequence.PPQ, 4);
			Track track = seq.createTrack();
			
			for (int i = 0; i < 61; i++) {
				track.add(makeEvent(144, 1, i+30, 100, i));
				track.add(makeEvent(128, 1, i+30, 100, i+5));
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