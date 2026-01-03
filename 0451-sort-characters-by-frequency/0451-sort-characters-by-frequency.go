func frequencySort(s string) string {
    freq:=make(map[rune]int);

    for _,c:=range s{
        freq[c]++;
    }

    n:=len(s)

    bucket:=make([][]rune,n+1);
    for ch,count:=range freq{
        bucket[count]=append(bucket[count],ch)
    }

    result:=make([]rune,0,n)
    for i:=n;i>0;i--{
        for _,c:=range bucket[i]{
            for j:=0;j<i;j++{
                result=append(result,c)
            }
        }
    }

    return string(result)
}