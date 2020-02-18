<?php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $k = count($nums);
        $i = $j = 0;
        $ct = 1;
        while($i<$k-1 && $ct<$k){
            if($nums[$i] == $nums[$ct]){
                $j+=1;
            }
            else {
                $i = $i + 1;
                
                $nums[$i] = $nums[$ct];
                
            }
            $ct+=1;
        }
        return $k - $j;
    }
}