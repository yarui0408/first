using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.ComponentModel.Design;

namespace BookSopTotu
{
    public partial class books : Form
    {
        public books()
        {
            InitializeComponent();
            populate();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label_Click(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }





        private void Filter()
        {
            Con.Open();
            string query = "select *from BookTbl where BCat='" + TypeSearch.SelectedItem.ToString() + "'";
            SqlDataAdapter sda = new SqlDataAdapter(query, Con);
            SqlCommandBuilder builder = new SqlCommandBuilder(sda);
            var dataset = new DataSet();
            sda.Fill(dataset);
            booklist.DataSource = dataset.Tables[0];

            Con.Close();
        }
        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            Filter();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            populate();


        }


        int key = 0;
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            BookTitle.Text = booklist.SelectedRows[0].Cells[1].Value.ToString();
            BookAuthor.Text = booklist.SelectedRows[0].Cells[2].Value.ToString();
            BookType.SelectedItem = booklist.SelectedRows[0].Cells[3].Value.ToString();
            BookPrice.Text = booklist.SelectedRows[0].Cells[5].Value.ToString();
            BookNum.Text = booklist.SelectedRows[0].Cells[4].Value.ToString();
            if (BookTitle.Text == "")
            {
                key = 0;
            }
            else
            {
                key = Convert.ToInt32(booklist.SelectedRows[0].Cells[0].Value.ToString());
            }
        }

        SqlConnection Con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\benye\Documents\bookShopDB.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False");

        private void populate()
        {
            Con.Open();
            string query = "select *from BookTbl";
            SqlDataAdapter adapter = new SqlDataAdapter(query, Con);
            SqlCommandBuilder sqlCommandBuilder = new SqlCommandBuilder(adapter);
            var dataset = new DataSet();
            adapter.Fill(dataset);
            booklist.DataSource = dataset.Tables[0];

            Con.Close();
        }







        private void Savebutton_Click(object sender, EventArgs e)
        {
            if (BookTitle.Text == "" || BookAuthor.Text == "" || BookType.SelectedIndex == -1 || BookPrice.Text == "" || BookNum.Text == "")
            {
                MessageBox.Show("信息缺失！！！");
            }
            else
            {
                try
                {
                    Con.Open();
                    string query = "insert into BookTbl values('" + BookTitle.Text + "','" + BookAuthor.Text + "','" + BookType.SelectedItem.ToString() + "'," + BookNum.Text + "," + BookPrice.Text + ")";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("书籍信息保存成功！！！");
                    Con.Close();
                    populate();
                    Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }
        }

        private void BookAuthor_TextChanged(object sender, EventArgs e)
        {

        }

        private void Reset()
        {
            BookTitle.Text = " ";
            BookAuthor.Text = " ";
            BookType.SelectedIndex = -1;
            BookPrice.Text = " ";
            BookNum.Text = " ";

        }
        private void Resetbutton_Click(object sender, EventArgs e)
        {

            Reset();

        }

        private void Deletebutton_Click(object sender, EventArgs e)
        {
            if (key == 0)
            {
                MessageBox.Show("信息缺失！！！");
            }
            else
            {
                try
                {
                    Con.Open();
                    string query = "delete from BOOKTbl where BId=" + key + "";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("用户信息删除成功！！！");
                    Con.Close();
                    populate();
                    Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }

        }

        private void Editbutton_Click(object sender, EventArgs e)
        {

            if (BookTitle.Text == "" || BookAuthor.Text == "" || BookType.SelectedIndex == -1 || BookPrice.Text == "" || BookNum.Text == "")
            {
                MessageBox.Show("信息缺失！！！");
            }
            else
            {
                try
                {
                    Con.Open();
                    string query = "update BOOKTbl set BTitle='" + BookTitle.Text + "',BAuthor='" + BookAuthor.Text + "',BCat='" + BookType.SelectedItem.ToString() + "',BQty=" + BookNum.Text + ",BPrice=" + BookPrice.Text + " where BId=" + key + "";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("书籍信息更新成功！！！");
                    Con.Close();
                    populate();
                    Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }
    
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
    }
}
