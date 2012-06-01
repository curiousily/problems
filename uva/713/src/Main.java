import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static int N;

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(terminalReader());
		N = Integer.valueOf(scanner.nextLine());
		for(int i = 0; i < N; i++) {
			String line = scanner.nextLine();
			String[] numbers = line.split(" ");
			BigInteger first = new BigInteger(new StringBuffer(numbers[0]).reverse().toString());
			BigInteger second = new BigInteger(new StringBuffer(numbers[1]).reverse().toString());
			StringBuffer reversedSum = new StringBuffer(first.add(second).toString()).reverse();
			String result = reversedSum.toString().replaceFirst("0*", "");
			System.out.println(result);
		}
	}

	private static BufferedReader fileReader() throws FileNotFoundException {
		return new BufferedReader(new FileReader(new File("in.txt")));
	}

	private static BufferedReader terminalReader() {
		return new BufferedReader(new InputStreamReader(System.in));
	}

}