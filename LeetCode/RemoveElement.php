<?php
class Solution {

/**
 * @param Integer[] $nums
 * @param Integer $val
 * @return Integer
 */
function removeElement(&$nums, $val) {
    $k = count($nums);
    $ct = 0;
    for ($i=0;$i<$k;$i++){
        if ($nums[$i] != $val){
            $nums[$ct] = $nums[$i];
            $ct++;
        }
    }
    return $ct;
}
}