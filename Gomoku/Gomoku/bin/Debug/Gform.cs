using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Gomoku
{
    public partial class Gform : Form
    {
        int dim;

        Cell C;
        Cell [,]Cs;
        int x;
        int y;
        COLOUR Turn = COLOUR.BLUE;
        int WC =5;
        int C1;
        int C2;


        public Gform()
        {
            InitializeComponent();
        }

        private void Gform_Load(object sender, EventArgs e)
        {

        }


        public void Innit()
        {

            Cs = new Cell[dim, dim];

            for (int i = 0; i < dim; i++)
            {
                for (int c = 0; c < dim; c++)
                {
                    int H = (GRID.Height / dim - 10);
                    int W = GRID.Width / dim - 10;
                    C = new Cell(H, W);
                    GRID.Controls.Add(C);

                    if (Human.Checked)
                    {
                        C.Click += new System.EventHandler(WHENCELLCLICKED);
                    }
                    else 
                    {
                        C.Click += new System.EventHandler(WHENCELLCLICKEDCMP);
                    
                    }


                    Cs[i,c] = C;
                
                }

            }



        }

        private void Start_Click(object sender, EventArgs e)
        {

            GRID.Controls.Clear();
            if (Five.Checked)
            {
                dim = 5;
            }
            else if (Ten.Checked)
            {
                dim = 10;
            }
            else if (Fifteen.Checked)
            {
                dim = 15;
            }
            else
            {
                MessageBox.Show("CHAWLA NA MARR!!!!!! SELECT KR ");
            }

            Innit();


        }
        public void WHENCELLCLICKED(object sender, EventArgs e)
        {

            Cell C = (Cell)sender;
            

            if (C.Occupier != COLOUR.WHITE)
            {
                MessageBox.Show("ALREADY SELECTED!!!!!!!!!!!");
                return;

            }
            else
            {
                C.Occupier = Turn;

                if (Turn == COLOUR.BLUE)
                {
                    C.BackColor = Color.Blue;
                }
                else
                {
                    C.BackColor = Color.Red;
                }


            }



            if (If_Win(Turn))
            {
            
                MessageBox.Show(C.Occupier.ToString() ,"WINS");
                GRID.Controls.Clear(); 
                
            }
            change_Turn();
             
        }

        public void WHENCELLCLICKEDCMP(object sender, EventArgs e)
        {

            Cell C = (Cell)sender;
            int i;
            for (i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    if (C.Occupier != COLOUR.WHITE)
                    {
                        MessageBox.Show("ALREADY SELECTED!!!!!!!!!!!");
                        return;

                    }
                    else
                    {
                        C.Occupier = Turn;
                        if (Turn == COLOUR.BLUE)
                        {
                            C.BackColor = Color.Blue;
                        }
                        else
                        {
                            C.BackColor = Color.Red;
                        }
                    }

                }
                else
                {
                     COMPUTER_TURN();   
                    Cs[x,y].Occupier = this.Turn;


                    if(Turn == COLOUR.BLUE)
                
                        Cs[x, y].BackColor = Color.Blue;
                    else
                        Cs[x, y].BackColor = Color.Red;


                }

                

               if (If_Win(Turn))
                {
                //    if (C1 == 1)
                //    {
                //        change_Turn();

                //        C.Occupier = Turn;
                //    }
                    if (i == 1)
                    {
                        C.Occupier = Cs[x,y].Occupier;
                    
                    }

                    MessageBox.Show(C.Occupier.ToString(), "WINS");

                    GRID.Controls.Clear();
                    break;
        
                }
               change_Turn();
 
            }

 
        }

        public void COMPUTER_TURN()
        {
        
            COLOUR T = this.Turn;
            Random rnd = new Random();
            do
            {
                    x  = rnd.Next(0, dim);
                    y  = rnd.Next(0, dim);

            } while(Cs[x,y].Occupier != COLOUR.WHITE);

            
           C_WIN();
           if (C1 != 1)
           {
               C2_WIN();
               
           }else
           {
               return;
           }

           C1 = 0;
        }

        public void change_Turn()
        {

            if (Turn == COLOUR.RED)
                Turn = COLOUR.BLUE;
            else
                Turn = COLOUR.RED;

        }


        public bool If_Win(COLOUR T)
        {
            for (int r = 0; r < dim; r++)
            {
                for (int c = 0; c < dim; c++)
                {
                    if(DoIwin(r,c,T))
                    {
                        return true;
                    }
                   
                }
            }



            return false;

        }


        public void C_WIN()
        {
            COLOUR T = this.Turn;
            for (int i = 0; i < dim; i++)
            {
                for (int c = 0; c < dim; c++)
                {
                    if (Cs[i, c].Occupier == COLOUR.WHITE)
                    {
                        Cs[i, c].Occupier = T;
                        if (If_Win(T))
                        {
                            C1 = 1;                   
                            x = i;
                            y = c;
                            Cs[i, c].Occupier = COLOUR.WHITE;
                            return;
                        }
                        else
                        {
                            Cs[i, c].Occupier = COLOUR.WHITE;

                        }
                    }
                }

            }
                
        }

        public void C2_WIN()
        {
            change_Turn();
          COLOUR  T = this.Turn;



            for (int i = 0; i < dim; i++)
            {
                for (int c = 0; c < dim; c++)
                {
                    if (Cs[i, c].Occupier == COLOUR.WHITE)
                    {

                        Cs[i, c].Occupier = T;
                        if (If_Win(T))
                        {
                            C2 = 1;

                            x = i;
                            y = c;
                            Cs[i, c].Occupier = COLOUR.WHITE;
                            change_Turn();
                            return;
                        }
                        else
                        {
                            Cs[i, c].Occupier = COLOUR.WHITE;
                        
                        }

                    }

                }

            }

            change_Turn();
  
        }


        public bool DoIwin(int r,int c,COLOUR T)
        {
         if (Is_horizontal(r, c, T) || Is_vertical(r, c, T) || Is_Diagnol_135(r, c, T) || Is_Diagnol_45(r, c, T))
                        return true;
         else
             return false;
        
        }


        public bool Is_horizontal(int r ,int c,COLOUR T)
        {

            for (int i = 0; i < WC; i++)
            {
                if (c + i < dim)
                {
                    if (Cs[r, c + i].Occupier != T)
                        return false;

                }
                else
                    return false;
            }
               return true;
        }
        public bool Is_vertical(int r, int c, COLOUR T)
        {

            for (int i = 0; i < WC; i++)
            {
                if (r + i < dim)
                {
                    if (Cs[r + i, c].Occupier != T)
                        return false;

                }
                else
                    return false;
            }
            return true;
        }
        public bool Is_Diagnol_135(int r, int c, COLOUR T)
        {

            for (int i = 0; i < WC; i++)
            {
                if (r - i >= 0)
                {
                    if (c - i >= 0)
                    {
                        if (Cs[r - i, c - i].Occupier != T)
                        {
                            return false;
                        }

                    }
                    else
                    {
                        return false;
                    }


                }
                else
                {
                    return false;
                }


               
            }
            return true;
        }
        public bool Is_Diagnol_45(int r, int c, COLOUR T)
        {

            for (int i = 0; i < WC; i++)
            {
                if (r - i >= 0)
                {
                    if (c + i < dim)
                    {
                        if (Cs[r - i, c +i].Occupier != T)
                        {
                            return false;
                        }

                    }
                    else
                    {
                        return false;
                    }


                }
                else
                {
                    return false;
                }



            }
            return true;
   
         
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }



        }

}


