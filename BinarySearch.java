public class BinarySearch {

    public int Search(int arr[],int l, int r, int x){

        if (r >= 1){
            int mid =  l + (r-1)/2;

            if (arr[mid] == x){
                return x;
            }

            if (arr[mid] > x){
                return Search(arr,l,r-1,x);
            }

            int search = Search(arr,l,r+1,x);
            return search;
        }

        return -1;
    }

    public static void main(String[] args) {
        BinarySearch br =  new BinarySearch();
        int arr[] =  new int[]{2,3,5,8,9,109,300,450,500};
        int l = 0;
        int r =  arr.length -1;
        int x = 109;

        int result = br.Search(arr,l,r,x);
        if (result == -1){
            System.out.println("Element not found");
        }else {
            System.out.println("Element found : " + result);
        }
    }

}
