void midptellipse(int a, int b,  
                  int h, int k) 
{ 
    float dx, dy, p1, p2, x, y; 
    x = 0; 
    y = b; 
  
    // Initial decision parameter of region 1 
    p1 = (b * b) - (a * a * b) +  
                     (0.25 * a * a); 
    dx = 2 * b * b * x; 
    dy = 2 * a * a * y; 
  
    // For region 1 
    while (dx < dy)  
    { 
  
        // Print points based on 4-way symmetb 
        cout << x + h << " , " << y + k << endl; 
        // cout << -x + h << " , " << y + k << endl; 
        // cout << x + h << " , " << -y + k << endl; 
        // cout << -x + h << " , " << -y + k << endl; 
  
        // Checking and updating value of 
        // decision parameter based on algorithm 
        if (p1 < 0) 
        { 
            x++; 
            dx = dx + (2 * b * b); 
            p1 = p1 + dx + (b * b); 
        } 
        else 
        { 
            x++; 
            y--; 
            dx = dx + (2 * b * b); 
            dy = dy - (2 * a * a); 
            p1 = p1 + dx - dy + (b * b); 
        } 
    } 
  
    // Decision parameter of region 2 
    p2 = ((b * b) * ((x + 0.5) * (x + 0.5))) +  
         ((a * a) * ((y - 1) * (y - 1))) - 
          (a * a * b * b); 
  
    // Plotting points of region 2 
    while (y >= 0) 
    { 
  
        // Print points based on 4-way symmetb 
        cout << x + h << " , " << y + k << endl; 
        // cout << -x + h << " , " << y + k << endl; 
        // cout << x + h << " , " << -y + k << endl; 
        // cout << -x + h << " , " << -y + k << endl; 
  
        // Checking and updating parameter 
        // value based on algorithm 
        if (p2 > 0)  
        { 
            y--; 
            dy = dy - (2 * a * a); 
            p2 = p2 + (a * a) - dy; 
        } 
        else 
        { 
            y--; 
            x++; 
            dx = dx + (2 * b * b); 
            dy = dy - (2 * a * a); 
            p2 = p2 + dx - dy + (a * a); 
        } 
    } 
} 
