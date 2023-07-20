import java.util.*;

class Solution {
    public static class Food{
        int idx;
        int foodTime;
        
        public Food(int idx, int foodTime){
            this.idx = idx;
            this.foodTime = foodTime;
        }
    }
    
    public int solution(int[] food_times, long k) {
        int answer = 0;
        
        List<Food> foodList = new ArrayList<>();
        
        for(int i = 0 ; i < food_times.length; i++){
            foodList.add( new Food(i + 1,food_times[i]));
        }
        
        Collections.sort(foodList, (o1,o2) -> o1.foodTime - o2.foodTime);
        
        int i = 0; 
        int preTime = 0;
        int foodCnt = food_times.length;
        
        for(Food food : foodList){
            long diff = food.foodTime - preTime;
            if(diff > 0){
                long spend = diff * foodCnt;
                if(k >= spend){
                    preTime = food.foodTime;
                    k -= spend;
                }else{
                    k = k % foodCnt;
                    Collections.sort(foodList.subList(i, foodList.size()), (o1,o2) -> o1.idx - o2.idx);
                    return foodList.get(i + (int) k).idx;
                }
            }
            i++;
            foodCnt--;
        }
        return -1;
    }
}
