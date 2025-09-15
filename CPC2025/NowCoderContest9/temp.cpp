while(step > EPS_STEP){
            bool improved = false;
            for(int t = 0; t < TOT_ATTEMPS; ++t) {
                int k; double m = CalZ2(x, y, &k); 
                double tx = rops[k].x - x, ty = rops[k].y - y;
                double val = hypot(tx, ty);
                if(val < 1e-18)tx = 1.0, ty = 0.0, val = 1.0;
                tx /= val; ty /= val;
                double curx = x + tx * step;
                double xury = y + ty * step;
                double curv = CalZ2(curx, xury, nullptr);
                if (curv > hv) { x = curx; y = xury; hv = curv; improved = true; break; }
                double angs[4] = {M_PI*0.25, -M_PI*0.25, M_PI*0.5, -M_PI*0.5};
                bool jumped = false;
                for (double a : angs) {
                    double cs = cos(a), sn = sin(a);
                    double tx2 = tx*cs - ty*sn, ty2 = tx*sn + ty*cs;
                    curx = x + tx2 * step; xury = y + ty * step;
                    curv = CalZ2(curx, xury, nullptr);
                    if (curv > hv) { x = curx; y = xury; hv = curv; improved = true; jumped = true; break; }
                }
                if (jumped) break;
            }
            if (!improved) step *= SHRINK;
        }