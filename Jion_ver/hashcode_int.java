import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

public class hashcode_int {

	public static void main(String[] args) throws IOException {
		String fileName="b_read_on.txt";
		BufferedReader br = null;
		
		// read file
		try {
			br = new BufferedReader(new FileReader(fileName));
		}catch(FileNotFoundException e) {
			System.out.println("Error in opening a file.\n");
			System.exit(0);
		}
		
		// first line
		String[] first=br.readLine().split(" ");
		int booksNum = Integer.parseInt(first[0]);
		int librariesNum = Integer.parseInt(first[1]);
		int days = Integer.parseInt(first[2]);

		// second line
		String[] second = br.readLine().split(" ");
		int[] scores = new int[second.length];
		for (int i=0;i<second.length;i++) {
			scores[i] = Integer.parseInt(second[i]);
		}
		
		Library_int[] libraries = new Library_int[librariesNum];
		for (int i=0;i<librariesNum;i++) {
			String[] info = br.readLine().split(" ");
			libraries[i] = new Library_int(
					Integer.parseInt(info[0]),Integer.parseInt(info[1]),Integer.parseInt(info[2]));
			String[] booksInLibrary = br.readLine().split(" ");
			for (int j=0;j<booksInLibrary.length;j++) {
				int book = Integer.parseInt(booksInLibrary[j]);
				libraries[i].books[j]=book;
			}
		}
		
		int result = 0;
		int rest = days;
		
		int count = 0;
		for (int i=0;i<libraries.length;i++) {
			rest -= libraries[i].sign;
			if(rest<0) break; // deadline 안에 signup 실패
			count++;
		}
		
		fileName="b_result.txt";
		PrintWriter outStream=null;
		try {
			outStream=new PrintWriter(fileName);
		}catch(FileNotFoundException e) {
			System.out.println("Exception Occurs");
			System.exit(0);
		}
		rest = days;
		outStream.println(count);
		for (int i=0;i<libraries.length;i++) {
			rest -= libraries[i].sign;
			if(rest<0) break; // deadline 안에 signup 실패
			int maxBook = rest*libraries[i].ship;
			int scannedBook;
			if(maxBook<=libraries[i].booksNum) scannedBook = maxBook;
			else scannedBook = libraries[i].booksNum;
			outStream.println(i+" "+scannedBook);
			
			for (int j=0;j<scannedBook;j++) {
				outStream.print(libraries[i].books[j]+" ");
			}
			outStream.println();
		}
		outStream.close();
	}
	
}

class Library_int {
	
	int booksNum, sign, ship;
	int[] books;
	
	Library_int(){}
	Library_int(int booksNum, int sign, int ship){
		this.booksNum = booksNum;
		this.sign = sign;
		this.ship = ship;
		books = new int[booksNum];
	}
	
}
