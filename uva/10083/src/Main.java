import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(terminalReader());
		int t, a, b;
		while (scanner.hasNextInt()) {
			t = scanner.nextInt();
			a = scanner.nextInt();
			b = scanner.nextInt();
			
			System.out.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
			if(t == 1) {
				System.out.println("is not an integer with less than 100 digits.");
				continue;
			}
			if(a == b) {
				System.out.println("1");
				continue;
			}
			if(a%b != 0) {
				System.out.println("is not an integer with less than 100 digits.");
				continue;
			}

			if((a-b)*Math.log10(t) > 99) {
				System.out.println("is not an integer with less than 100 digits.");
				continue;
			}
			BigInteger X, Y;
			X = BigInteger.valueOf(t);
			Y = BigInteger.valueOf(t);
			X = X.pow(a);
			Y = Y.pow(b);
			X = X.subtract(BigInteger.ONE);
			Y = Y.subtract(BigInteger.ONE);
			if(Y.compareTo(BigInteger.valueOf(0)) == 0) {
				System.out.println("is not an integer with less than 100 digits.");
				continue;
			}
			System.out.println(X.divide(Y).toString());
		}
	}

	private static BufferedReader fileReader() throws FileNotFoundException {
		return new BufferedReader(new FileReader(new File("in.txt")));
	}

	private static BufferedReader terminalReader() {
		return new BufferedReader(new InputStreamReader(System.in));
	}
}