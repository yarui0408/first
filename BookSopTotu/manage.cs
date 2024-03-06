using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BookSopTotu
{
    public partial class manage : Form
    {
        public manage()
        {
            InitializeComponent();
        }
        SqlConnection Con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\benye\Documents\bookShopDB.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False");


        private void panel8_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel9_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {
            Login obj = new Login();
            obj.Show();
            this.Hide();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            books obj = new books();
            obj.Show();
            this.Hide();
        }

        private void label6_Click(object sender, EventArgs e)
        {
            users obj = new users();
            obj.Show();
            this.Hide();
        }

        private void label8_Click(object sender, EventArgs e)
        {
            manage obj = new manage();
            obj.Show();
            this.Hide();
        }

        private void manage_Load(object sender, EventArgs e)
        {
            Con.Open();
            SqlDataAdapter sda=new SqlDataAdapter("Select sum(BQty)from BOOKTbl",Con);
            DataTable dt = new DataTable();
            sda.Fill(dt);
            BookStockLbl.Text = dt.Rows[0][0].ToString();

            SqlDataAdapter sdaa = new SqlDataAdapter("Select sum(Amount)from BillTbl", Con);
            DataTable dtt = new DataTable();
            sdaa.Fill(dtt);
            AmountLbl.Text = dtt.Rows[0][0].ToString();

            SqlDataAdapter sdaaa = new SqlDataAdapter("Select Count(*)from UserTbl", Con);
            DataTable dttt = new DataTable();
            sdaaa.Fill(dttt);
            UserTotalLbl.Text = dttt.Rows[0][0].ToString();
            Con.Close();
        }

        private void label7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void BookStockLbl_Click(object sender, EventArgs e)
        {

        }

        private void AmountLbl_Click(object sender, EventArgs e)
        {

        }

        private void UserTotalLbl_Click(object sender, EventArgs e)
        {

        }

        private void panel4_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
