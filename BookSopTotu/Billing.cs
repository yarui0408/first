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
    public partial class Billing : Form
    {
        public Billing()
        {
            InitializeComponent();
            populate();
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
            dgvlist.DataSource = dataset.Tables[0];

            Con.Close();
        }
        int key = 0,stock=0;
        private void booklist_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            boxBookTitle.Text = dgvlist.SelectedRows[0].Cells[1].Value.ToString();
            boxBookPrice.Text = dgvlist.SelectedRows[0].Cells[5].Value.ToString();
            //boxBookNum.Text = dgvlist.SelectedRows[0].Cells[4].Value.ToString();
            boxBookNum.Text = "";
            if (boxBookTitle.Text == "")
            {
                key = 0;
                stock = 0;
            }
            else
            {
                key = Convert.ToInt32(dgvlist.SelectedRows[0].Cells[0].Value.ToString());
                stock = Convert.ToInt32(dgvlist.SelectedRows[0].Cells[4].Value.ToString()) ;
            }
        }

        private void label7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        private void Reset()
        {
            boxBookTitle.Text = " ";
            
            boxBookPrice.Text = " ";
            boxBookNum.Text = " ";

        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            Reset();
        }
        int n = 0,billTotal=0;
        private void buttonAddToCart_Click(object sender, EventArgs e)
        {
            
            if(boxBookNum.Text==""||Convert.ToInt32(boxBookNum.Text)>stock)
            {
                MessageBox.Show("库存不足！！！");
            }
            else
            {
                int  total = Convert.ToInt32(boxBookNum.Text) * Convert.ToInt32(boxBookPrice.Text);
                DataGridViewRow newRow = new DataGridViewRow();
                newRow.CreateCells(dgvShoppingCart);
                newRow.Cells[0].Value = n+1;
                newRow.Cells[1].Value = boxBookTitle.Text;
                newRow.Cells[3].Value =boxBookNum.Text;
                newRow.Cells[2].Value =boxBookPrice.Text;
                newRow.Cells[4].Value = total;
                dgvShoppingCart.Rows.Add(newRow);
                n++;
                UpdateBook();
                billTotal += total;
                buttonSettlement.Text = "￥" + billTotal;
            }    
        }

        private void buttonSettlement_Click(object sender, EventArgs e)
        {
           
            if (dgvShoppingCart.Rows[0].Cells[0]==null)
            {
                MessageBox.Show("购物车无需结算！！！");
            }
            else
            {
               
                try
                {
                    Con.Open();
                    string query = "insert into BillTbl values('" + labelUserNmae.Text + "'," + billTotal +  ")";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("订单信息保存成功！！！");
                    Con.Close();
                    //populate();
                    //Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
                printDocument1.DefaultPageSettings.PaperSize = new System.Drawing.Printing.PaperSize("pprnm", 285, 660);
                if (printPreviewDialog1.ShowDialog() == DialogResult.OK)
                {
                    printDocument1.Print();
                }
            }
        }

        int prodid, prodqty, prodprice, tottal, pos = 60;

        private void label9_Click(object sender, EventArgs e)
        {
            Login obj = new Login();
            obj.Show();
            this.Hide();
        }

        private void label_Click(object sender, EventArgs e)
        {
            labelUserNmae.Text=Login.UserName;
        }

        string prodname;
        private void printDocument1_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            e.Graphics.DrawString("all顺遂书店", new Font("宋体", 12, FontStyle.Bold), Brushes.Red, new Point(80));
            e.Graphics.DrawString("编号 产品 价格 数量 总计", new Font("宋体", 10, FontStyle.Bold), Brushes.Red, new Point(26,40));
            foreach(DataGridViewRow row in dgvShoppingCart.Rows )
            {
                prodid = Convert.ToInt32(row.Cells["dataGridViewTextBoxColumn1"].Value);
                prodname = "" + row.Cells["dataGridViewTextBoxColumn2"].Value;
                prodqty = Convert.ToInt32(row.Cells["dataGridViewTextBoxColumn4"].Value); 
                prodprice = Convert.ToInt32(row.Cells["dataGridViewTextBoxColumn3"].Value);
                tottal = Convert.ToInt32(row.Cells["dataGridViewTextBoxColumn5"].Value);
                e.Graphics.DrawString("" + prodid, new Font("宋体", 8, FontStyle.Bold), Brushes.Blue, new Point(26, pos));
                e.Graphics.DrawString("" + prodname, new Font("宋体", 8, FontStyle.Bold), Brushes.Blue, new Point(45, pos));
                e.Graphics.DrawString("" + prodqty, new Font("宋体", 8, FontStyle.Bold), Brushes.Blue, new Point(120, pos));
                e.Graphics.DrawString("" + prodprice, new Font("宋体", 8, FontStyle.Bold), Brushes.Blue, new Point(170, pos));
                e.Graphics.DrawString("" + tottal, new Font("宋体", 8, FontStyle.Bold), Brushes.Blue, new Point(235, pos));
                pos += 20;
            }
            e.Graphics.DrawString("订单总额：￥"+billTotal, new Font("宋体", 12, FontStyle.Bold), Brushes.Crimson, new Point(60, pos+50));
            e.Graphics.DrawString("********all顺遂书店********" , new Font("宋体", 10, FontStyle.Bold), Brushes.Crimson, new Point(40, pos + 85));
            dgvShoppingCart.Rows.Clear();
            dgvShoppingCart.Refresh();
            pos = 100;
            billTotal=0;
        }


        private void UpdateBook()
        {
            int newBookNum = stock - Convert.ToInt32(boxBookNum.Text);
            try
            {
                Con.Open();
                string query = "update BOOKTbl set BQty=" + newBookNum + " where BId=" + key + "";
                SqlCommand cmd = new SqlCommand(query, Con);
                cmd.ExecuteNonQuery();
                //MessageBox.Show("书籍库存信息更新成功！！！");
                Con.Close();
                populate();
                //Reset();
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message);

            }
        }
    }
}
