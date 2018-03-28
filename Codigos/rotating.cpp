void Rating_Calipers(){
    for(int i=0, j=2; i<n; i++){
        // P[j] debe ser el punto mas lejano a la linea P[i], P[(i+1)%n]:
        while(area(P[i], P[(i+1)%n], P[(j+1)%n]) > area(P[i], P[(i+1)%n], P[j])) j = (j+1)%n;
     
        // Par antipodal: i, j
        // Par antipodal: (i+1)%n, j
    }
}
