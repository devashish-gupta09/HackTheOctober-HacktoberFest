
public class Duplicate_string {
    public static void main(String[] args) {
        char [] arr = new char [] {'a','b','c','d','a','b','c'};

        System.out.println("Duplicate elements in given array: ");
        //Searches for duplicate element
        for(int i = 0; i < arr.length; i++) {
            for(int j = i + 1; j < arr.length; j++) {
                if(arr[i] == arr[j])
                    System.out.println(arr[j]);
            }
        }
    }
}
