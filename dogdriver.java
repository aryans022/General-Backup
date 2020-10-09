public class dogdriver {
	public static void main(String[] args) {
		dog elm = new dog();
		elm.age = 5;
		elm.name = "Elma";
	
		elm.bark();
	}
}

class dog {
	
	String name = "nothing (yet)";
	String breed = "Dalmatian";
	int age = 1;
	
	void bark() {
		System.out.println("Woof! I am a " + breed + " called " + name + " and I am " + age + " years old");
	}
}