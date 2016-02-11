//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BackTracking.h"
#include "Main.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TBackTracking::TBackTracking(TMainForm * main, int time, bool CreateSuspended)
	: TThread(CreateSuspended)
{
	m_main = main;
	m_time = time;
	m_CreateTree = true;

	Priority = tpHigher;
	FreeOnTerminate = true;
}
//---------------------------------------------------------------------------
void __fastcall TBackTracking::Execute()
{
	double diff;
	time_t start, end;

	const int n = 9;

	m_main->m_aux.size();	//limpa o vetor auxiliar

	start = clock();	//armazena o tempo inicial

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if(m_main->m_grid[row][col] == 0)	//verifica se a posição está vazia
			{
				for (int i = 1; i <= n; i++)	//inicia os teste de 1 a 9
				{
					if(Terminated)
					{
						m_msg = " Sudoku >> Resolução finalizada pelo usuário";
						Synchronize(&SetMessage);
						return;
					}

					if (m_main->isValid(row,col,i))
					{
						m_main->m_grid[row][col] = i;												//alimenta a matriz
						m_main->m_aux.push_back(std::make_pair(row,col));   //alimenta o vetor aux

						m_col = col;
						m_row = row;

						Synchronize(&SelectCell);							//seleciona a célula
						Synchronize(&UpdateGridView);					//atualiza o grid
						Sleep(m_time);
						break;
					}
					else
					{
						/**
						 * Caso não exista uma solução válida
						 * incrementa o valor nas células anteriores até encontrar
						 * uma solução e repete o processo nas próxmas células
						 */

						if (i == n)
						{
							if (m_main->m_aux.size() > 0)
							{
								for (int j = m_main->m_aux.size()-1; j >= 0; j--)
								{
									if(Terminated)
									{
										m_msg = " Sudoku >> Resolução finalizada pelo usuário";
										Synchronize(&SetMessage);
										return;
									}

									row = m_main->m_aux[j].first;
									col = m_main->m_aux[j].second;
									i = m_main->m_grid[m_main->m_aux[j].first][m_main->m_aux[j].second];

									m_main->m_grid[row][col] = 0;

									m_col = col;
									m_row = row;
									Synchronize(&SelectCell);							//seleciona a célula
									Synchronize(&UpdateGridView);         //atualiza o grid

									m_main->m_aux.pop_back();
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
	Synchronize(&GetCreateTree);
	if (m_CreateTree)
	{
  	//cria a arvore da solução
		m_main->CreateTreeSolve();
	}

	m_msg = " Sudoku >> Tempo de solução: " + FloatToStr(diff);

	Synchronize(&SetMessage);
}
//---------------------------------------------------------------------------
void __fastcall TBackTracking::UpdateGridView()
{
	//percorre a matriz aux e alimenta o grid

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (m_main->m_grid[i][j] != 0)
			{
				m_main->m_sudoku->Cells[j][i] = IntToStr(m_main->m_grid[i][j]);
			}
			else
			{
				m_main->m_sudoku->Cells[j][i] = "";
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TBackTracking::SetMessage()
{
	if (Terminated) m_main->m_status->SelAttributes->Color = clRed;

	m_main->m_status->Lines->Add(m_msg);
	m_main->m_solve->Enabled = true;
	m_main->m_create->Enabled = true;
	m_main->m_clean->Enabled = true;
	m_main->m_ToolCancel->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TBackTracking::SelectCell()
{
	m_main->m_sudoku->Col = m_col;
	m_main->m_sudoku->Row = m_row;
}
//---------------------------------------------------------------------------
void __fastcall TBackTracking::GetCreateTree()
{
	m_CreateTree = m_main->m_CreateTreeSolve->Checked;
}
//---------------------------------------------------------------------------
