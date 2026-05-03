var solve = function(x, n) {
    if (n === 0) return 1;
    let ans = solve(x,Math.floor(n/2));
    if (n % 2 === 0) {
        return ans * ans;
    }
    return ans * ans * x;
}
var myPow = function(x, n) {
    if (n==0) return 1.0;
    if(n<0){
        n=-n;
        return 1/solve(x,n);
    }
    return  solve(x,n);
};