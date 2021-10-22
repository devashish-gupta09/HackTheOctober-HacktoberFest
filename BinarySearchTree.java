

public class BinarySearchTree {

    //Binary Search
    public int search(int arrs[], int l, int r, int x) {

        if (r >= 1) {
            int midle = l + (r - 1) / 2;

            if (arrs[midle] == x) {
                return midle;
            }

            if (arrs[midle] > x) {
                return search(arrs, l, r - 1, x);
            }
            //searching right side
            int searchs = search(arrs, l, r + 1, x);

            return searchs;
        }

        return -1;
    }

    public static void main(String[] args) {

        BinarySearchTree bs = new BinarySearchTree();
        int arr[] = new int[]{2, 5, 10, 18,23,44,67,70,71,72,75,77};
        int l = 0;
        int r = arr.length - 1;
        int x = 18;
        long startTime = System.nanoTime();


        int result = bs.search(arr, l, r, x);


        if (result == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found " + result);
            
        }
    }

}
