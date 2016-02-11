//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	//inicializa a matriz auxiliar

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_grid[i][j] = 0;
			m_color[i][j] = 0;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_createClick(TObject *Sender)
{
	const int n = 3;

	m_aux.clear();
	m_TreeSolve->Items->Clear();

	/**
	 * Algoritmo polinomial que cria aleatoriamente
	 * o tabuleiro do sudoku
	 */

	int x = rand() % 10; //semente

	for (int i = 0; i < n; i++, x++)
	{
		for (int j = 0; j < n; j++, x+=n)
		{
			for (int k = 0; k < n*n; k++, x++)
			{
				m_sudoku->Cells[n*i+j][k] = IntToStr((x % (n*n)) + 1);
			}
		}
	}

	/* Gera apenas um jogo
	for (int i = 0; i < n*n; i++)
	{
		for (int j = 0; j < n*n; j++)
		{
			int value = (i*n + i/n + j) % (n*n) + 1;
			m_sudoku->Cells[j][i] = IntToStr(value);
		}
	}
	*/

	//remove 5 numeros em cada quadrante

	const int square = 9;
	const int numbers = m_UpDownNumbers->Position;

	int minRows = 0, maxRows = 2;
	int minCols = 0, maxCols = 2;

	for (int i = 0; i < square; i++)
	{
		for (int j = 0; j < numbers; j++) //tenta remover 5 numeros
		{
			int row = (rand() % (maxRows + 1 - minRows)) + minRows;
			int col = (rand() % (maxCols + 1 - minCols)) + minCols;
			m_sudoku->Cells[col][row] = "";
		}

		minCols = maxCols + 1;
		maxCols += 3;

		if(maxCols > 8 )
		{
			minCols = 0;
			maxCols = 2;
		}

		if(maxRows == i)
		{
			minRows = maxRows + 1;
			maxRows += 3;
		}
	}

	this->FillGrixAux();

	m_status->SelAttributes->Color = clBlue;
	m_status->Lines->Add(" Sudoku >> Novo jogo criado");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_cleanClick(TObject *Sender)
{
	//limpa o grid, matriz aux, treeview e status

	for (int i = 0; i < m_sudoku->RowCount; i++)
	{
		m_sudoku->Rows[i]->Clear();
		for (int j = 0; j < m_sudoku->ColCount; j++)
		{
			m_grid[i][j] = 0;
		}
	}
	m_status->Clear();
	m_TreeSolve->Items->Clear();
}
//---------------------------------------------------------------------------
bool TMainForm::isValid(int row, int col, int num)
{
	if (this->isValidSquade(row,col,num) && this->isValidRow(row,0,num) &&
			this->isValidCol(0,col,num))
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
bool TMainForm::isValidRow(int row, int col, int num)
{
	if( col <= 8 )
	{
		int value = 0;

		if(m_grid[row][col] != 0)
		{
			value = m_grid[row][col];
		}

		if(  value== num ) return false;
		else return isValidRow(row,col + 1,num);
	}
	return true;
}
//---------------------------------------------------------------------------
bool TMainForm::isValidCol(int row, int col, int num)
{
	if( row <= 8 )
	{
		int value = 0;

		if(m_grid[row][col] != 0)
		{
			value = m_grid[row][col];
    }

		if( value == num ) return false;
		else return isValidCol(row + 1,col,num);
	}
	return true;
}
//---------------------------------------------------------------------------
bool TMainForm::isValidSquade(int row, int col, int num)
{
	//identifica o quadrante pela linha e coluna

	std::vector< std::pair<int,int> > squade;
	squade = this->GetSquade(row,col);

	//percorre o quadrante localizado comparando os valores

	for (int r = squade[0].first; r <= squade[0].second; r++)
	{
		for (int c = squade[1].first; c <= squade[1].second; c++)
		{
			if(m_grid[r][c] != 0)
			{
				int value = m_grid[r][c];
				if (value == num) return false;
			}
		}
	}
	return true;
}
//---------------------------------------------------------------------------
std::vector< std::pair<int,int> > TMainForm::GetSquade(int row, int col)
{
	int posRow = (int)row / 3;
	int posCol = (int)col / 3;

	std::vector< std::pair<int,int> > squade;

	if (posRow == 0) squade.push_back(std::make_pair(0,2));
	if (posRow == 1) squade.push_back(std::make_pair(3,5));
	if (posRow == 2) squade.push_back(std::make_pair(6,8));

	if (posCol == 0) squade.push_back(std::make_pair(0,2));
	if (posCol == 1) squade.push_back(std::make_pair(3,5));
	if (posCol == 2) squade.push_back(std::make_pair(6,8));

	return squade;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_sudokuDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
					TGridDrawState State)
{

	TColor color = clBlack;
	Rect = m_sudoku->CellRect(ACol,ARow);

	//localiza o quadrante da linha e da coluna

	int posR = (int)ARow / 3;
	int posC = (int)ACol / 3;

	//altera a cor de fundo dos quadrantes escolhidos no if

	if (ARow >= m_sudoku->Selection.Top && ARow <= m_sudoku->Selection.Bottom &&
			ACol >= m_sudoku->Selection.Left && ACol <= m_sudoku->Selection.Right)
	{
		//caso o grid selecionado a cor é alterada para laranja
		m_sudoku->Canvas->Brush->Color = (TColor) 0x00C0EAFF;
	}
	else
	{
		if(m_color[ARow][ACol] == 1) //caso seja a posição de preenchimento
		{
			color = clRed;
		}

		if( ((posR == 0 || posR == 2) && (posC == 0 || posC == 2)) ||
				(posR == 1 && posC == 1) )
		{
			std::vector< std::pair<int,int> > squade;
			squade = this->GetSquade(ARow,ACol);

			if(squade.size() > 0)
			{
				if (ARow >= squade[0].first && ARow <= squade[0].second &&
						ACol >= squade[1].first && ACol <= squade[1].second)
				{
					//altera a cor para cinza apenas dos quadrantes
					m_sudoku->Canvas->Brush->Color = (TColor)0x00E9E9E9;
				}
			}
		}
	}

	//define a cor padrão da fonte como preto
	m_sudoku->Canvas->Font->Color = color;

	m_sudoku->Canvas->FillRect(Rect);

	//caso o grid selecionado desenha a borda laranja
	if (ARow >= m_sudoku->Selection.Top && ARow <= m_sudoku->Selection.Bottom &&
			ACol >= m_sudoku->Selection.Left && ACol <= m_sudoku->Selection.Right)
	{
		m_sudoku->Canvas->Pen->Color = (TColor)0x0015A5FF;//0x00FBC79B;
		m_sudoku->Canvas->MoveTo(Rect.left, Rect.bottom);
		m_sudoku->Canvas->LineTo(Rect.right, Rect.bottom);
		m_sudoku->Canvas->LineTo(Rect.right, Rect.top - 1);

		if(ARow == m_sudoku->Selection.Top)
		{
			m_sudoku->Canvas->MoveTo(Rect.left, Rect.top);
			m_sudoku->Canvas->LineTo(Rect.right, Rect.top);
		}
		if(ACol == m_sudoku->Selection.Left)
		{
			m_sudoku->Canvas->MoveTo(Rect.left, Rect.top);
			m_sudoku->Canvas->LineTo(Rect.left, Rect.bottom);
		}
	}

	//centraliza os valores nas células

	UnicodeString value = m_sudoku->Cells[ACol][ARow];

	int wText = Canvas->TextWidth(value) / 2;
	int wTotal = m_sudoku->ColWidths[ACol] / 2;

	int hText = Canvas->TextHeight(value) / 2;
	int hTotal = m_sudoku->RowHeights[ARow] / 2;

	m_sudoku->Canvas->TextOut(Rect.left + (wTotal-wText), Rect.top + (hTotal-hText),value);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_solveClick(TObject *Sender)
{

	/**
	 * Inicia o algoritmo backtracking com thread
	 * o thread é utilizado apenas para definir um tempo entre uma solução
	 * e outra com o objetivo de permitir ao usuário visualizar o processo
	 * de solução do sudoku
	 */

	m_TreeSolve->Items->Clear();

	m_status->SelAttributes->Color = clBlack;
	m_status->Lines->Add(" Sudoku >> Resolvendo o sudoku...");

	if(m_TimeReal->Checked)
	{
		m_ToolCancel->Enabled = false;
		this->BackTracking();
	}
	else if(m_Simulation->Checked)
	{
		m_create->Enabled = false;
		m_solve->Enabled = false;
		m_clean->Enabled = false;
		m_ToolCancel->Enabled = true;

		int time = m_UpDown->Position;

		m_backtracking = new TBackTracking(this,time,true);
		m_backtracking->Start();
	}

	/**
	 * Esse método é o algoritmo backtracking sem a criação da thread
	 * this->BackTracking();
	 */

	/**
	 * Esse método é o algoritmo backtracking de forma recursiva sem
	 * a criação da thread
	 * this->BackTrackingRecursive(0,0);
	 */
}
//---------------------------------------------------------------------------
void TMainForm::BackTracking()
{
	double diff;
	time_t start, end;

	m_aux.size(); //limpa o vetor auxiliar

	start = clock();	//armazena o tempo inicial

	for (int row = 0; row < m_sudoku->RowCount; row++)
	{
		for (int col = 0; col < m_sudoku->ColCount; col++)
		{
			if(m_grid[row][col] == 0)	//verifica se a posição está vazia
			{
				for (int i = 1; i <= 9; i++)	//inicia os teste de 1 a 9
				{
					if (this->isValid(row,col,i))
					{
						m_grid[row][col] = i;												//alimenta a matriz
						m_aux.push_back(std::make_pair(row,col));   //alimenta o vetor aux
						UpdateGridView();														//atualiza o grid
						break;
					}
					else
					{
						/**
						 * Caso não exista uma solução válida
						 * incrementa o valor nas células anteriores até encontrar
						 * uma solução e repete o processo nas próxmas células
						 */

						if (i == 9)
						{
							if (m_aux.size() > 0)
							{
								for (int j = m_aux.size()-1; j >= 0; j--)
								{
									row = m_aux[j].first;
									col = m_aux[j].second;
									i = m_grid[m_aux[j].first][m_aux[j].second];

									m_grid[row][col] = 0;

									m_aux.pop_back();
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	//calcula o tempo que o algoritmo encontrou a solução

	end = clock();
	diff = (double)(end-start) / ((double)CLOCKS_PER_SEC);

	//verifica se a arvore será criada
	if (m_CreateTreeSolve->Checked)
	{
  	//cria a arvore da solução
		this->CreateTreeSolve();
	}

	UnicodeString msg = " Sudoku >> Tempo de solução: " + FloatToStr(diff);
	m_status->Lines->Add(msg);
}
//---------------------------------------------------------------------------
void TMainForm::BackTrackingRecursive(int row, int col)
{
	if (row > 8) return;

	if (m_grid[row][col] != 0)
	{
		if( col < 8)
		{
			this->BackTrackingRecursive(row, col + 1);
		}
		else
		{
			this->BackTrackingRecursive(row + 1, 0);
    }
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (this->isValid(row,col,i))
			{
				m_grid[row][col] = i;
				UpdateGridView();

				if (col < 8) this->BackTrackingRecursive(row,col + 1);
				else this->BackTrackingRecursive(row + 1,0);
			}
		}
	 	m_grid[row][col] = 0;
		UpdateGridView();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Copiar1Click(TObject *Sender)
{
	TStringList * blist = new TStringList;
	TStringList * slist;
	TClipboard * clipboard = new TClipboard;

	for (int i = m_sudoku->Selection.Top; i <= m_sudoku->Selection.Bottom; i++)
	{
		slist = new TStringList;
		slist->Delimiter = '\t';
		for (int j = m_sudoku->Selection.Left; j <= m_sudoku->Selection.Right; j++)
		{
			slist->Add(m_sudoku->Cells[j][i]);
		}

		blist->Delimiter = '\r\n';
		blist->Add(slist->DelimitedText);
	}
	clipboard->AsText = blist->Text;

	delete blist;
	delete clipboard;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Colar1Click(TObject *Sender)
{
	TStringList * slist;
	TStringList * blist = new TStringList;
	TClipboard * clipboard = new TClipboard;

	blist->Text = clipboard->AsText;

	int row = m_sudoku->Row;
	int col = m_sudoku->Col;

	if(blist->Count > m_sudoku->RowCount)
	{
		m_sudoku->RowCount = blist->Count;
	}

	for(int i = 0; i < blist->Count; i++)
	{
		slist = new TStringList;slist->StrictDelimiter = true;
		slist->Delimiter = '\t';
		slist->DelimitedText = blist->Strings[i];

		for (int j = 0; j < slist->Count; j++)
		{
			UnicodeString val = slist->Strings[j];
			m_sudoku->Cells[col+j][row+i] = val;
		}
	}

	this->FillGrixAux();	//alimenta o grid aux com os dados da área de trans.

	delete blist;
	delete clipboard;
}
//---------------------------------------------------------------------------
void TMainForm::UpdateGridView()
{
	//percorre a matriz aux e alimenta o grid

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (m_grid[i][j] != 0)
			{
				m_sudoku->Cells[j][i] = IntToStr(m_grid[i][j]);
			}
			else
			{
				m_sudoku->Cells[j][i] = "";
			}
		}
	}
}
//---------------------------------------------------------------------------
void TMainForm::FillGrixAux()
{
	//percorre o componente grid e alimenta a matriz aux

	for (int i = 0; i < m_sudoku->RowCount; i++)
	{
		for (int j = 0; j < m_sudoku->ColCount; j++)
		{
			if (m_sudoku->Cells[j][i].IsEmpty())
			{
				m_grid[i][j] = 0;
				m_color[i][j] = 1; //marca a posição para ser destacada no grid
			}
			else
			{
				m_grid[i][j] = StrToInt(m_sudoku->Cells[j][i]);
				m_color[i][j] = 0;
			}
		}
	}
}
//---------------------------------------------------------------------------
void TMainForm::CreateTreeSolve()
{
	m_status->Lines->Add(" Sudoku >> Criando árvore de solução...");

	//cria o nó principal e seleciona

	TTreeNode * nodeMain = m_TreeSolve->Items->Add(NULL,"Sudoku");
	TTreeNode * selectNode = nodeMain;

	//seleciona o icone
	nodeMain->ImageIndex = 5;
	nodeMain->SelectedIndex = 5;

	//percorre a estrutura com a solução
	for (unsigned int i = 0; i < m_aux.size(); i++)
	{
		int value = m_grid[m_aux[i].first][m_aux[i].second]; //armazena o valor

		for (int j = 1; j <= 9; j++)
		{
			//cria o nós com todas as possibilidades ( 1 a 9 )
			TTreeNode * node = m_TreeSolve->Items->AddChild(selectNode,IntToStr(j));
			node->ImageIndex = 3;
			node->SelectedIndex = 3;
		}

		//localiza a possibilidade correta para criar os nós filhos

		TTreeNode * searchNode = selectNode->getFirstChild();
		while(searchNode != NULL)
		{
			int index = StrToInt(searchNode->Text);
			if (index == value)
			{
				selectNode = searchNode;
				selectNode->Data = &m_aux[i];		//armazena as posições de linha e coluna

				selectNode->ImageIndex = 4;
				selectNode->SelectedIndex = 4;
				break;
			}
			searchNode = searchNode->getNextSibling();
		}
	}
	m_TreeSolve->Items->GetFirstNode()->Expand(true); //expande a arvore finalizada
	m_TreeSolve->Selected = nodeMain;									//seleciona o nó principal
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_TreeSolveClick(TObject *Sender)
{
	//localiza o nó selecionado
	TTreeNode * node = m_TreeSolve->Selected;
	if (node)
	{
		if (node->ImageIndex==4) //verifica se é uma solução
		{
			//faz o casting para o tipo pair com a linha e coluna
			std::pair<int,int> * cell = static_cast<std::pair<int,int> *>(node->Data);
			if (cell)
			{
				//seleciona a célula no grid
				m_sudoku->Row = cell->first;
				m_sudoku->Col = cell->second;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	m_UpDown->Position = 500;
	m_UpDownNumbers->Position = 5;
	m_TimeReal->Checked = true;
	m_CreateTreeSolve->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_SimulationClick(TObject *Sender)
{
	m_time->Enabled = m_Simulation->Checked;
	m_UpDown->Enabled = m_Simulation->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_TimeRealClick(TObject *Sender)
{
	m_time->Enabled = m_Simulation->Checked;
	m_UpDown->Enabled = m_Simulation->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::m_ToolCancelClick(TObject *Sender)
{
	if (m_backtracking)
	{
		m_backtracking->Terminate();
	}
}
//---------------------------------------------------------------------------

