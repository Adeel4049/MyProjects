using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Windows.Forms;

namespace Gomoku
{
    public enum COLOUR {WHITE,BLUE,RED};

    class Cell: Button
    {
        
        public COLOUR Occupier;
        


      public Cell(int h,int w)
        {
            Occupier = COLOUR.WHITE;
            this.Height = h;
            this.Width = w;
     
   
        }

    }
}
