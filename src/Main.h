//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <clipbrd.hpp>
#include <ExtCtrls.hpp>
#include <vector>
#include <time.h>
#include "BackTracking.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components

	TToolBar *ToolBar1;
	TToolButton *m_create;
	TImageList *ImageList1;
	TToolButton *m_solve;
	TToolButton *m_clean;
	TStringGrid *m_sudoku;
	TTreeView *m_TreeSolve;
	TRichEdit *m_status;
	TPopupMenu *PopupMenu1;
	TMenuItem *Copiar1;
	TMenuItem *Colar1;
	TShape *Shape1;
	TRadioButton *m_TimeReal;
	TRadioButton *m_Simulation;
	TEdit *m_time;
	TLabel *Label1;
	TUpDown *m_UpDown;
	TCheckBox *m_CreateTreeSolve;
	TEdit *m_numbers;
	TUpDown *m_UpDownNumbers;
	TLabel *Label2;
	TToolButton *m_ToolCancel;
	TToolButton *ToolButton2;
	void __fastcall m_cleanClick(TObject *Sender);
	void __fastcall m_createClick(TObject *Sender);
	void __fastcall m_sudokuDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
																	 TGridDrawState State);
	void __fastcall m_solveClick(TObject *Sender);
	void __fastcall Copiar1Click(TObject *Sender);
	void __fastcall Colar1Click(TObject *Sender);
	void __fastcall m_TreeSolveClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall m_SimulationClick(TObject *Sender);
	void __fastcall m_TimeRealClick(TObject *Sender);
	void __fastcall m_ToolCancelClick(TObject *Sender);

private:

	TBackTracking * m_backtracking;		//ponteiro para a thread do backtracking

	/**
	 * Executa o algoritmo backtracking sem recursividade
	 */
	void BackTracking();

	/**
	 * Executa o algoritmo backtrcking recursivamente
	 * @param		row		Recebe a linha inicial
	 * @param		col		Recebe a coluna inicial
	 */
	void BackTrackingRecursive(int row, int col);

public:

	__fastcall TMainForm(TComponent* Owner);

	int m_grid[9][9];		//matriz auxiliar utilizada pelo backtracking
	int m_color[9][9];	//armazena as posi��es que devem ser preenchidas p/ encontrar a solu��o

	/**
	 * Vetor armazena todas as posi��es preenchidas pelo backtracking
	 * que � utilizado para retornar as ultimas posi��es caso encontre um conflito
	 */
	std::vector< std::pair<int,int> > m_aux;

	/**
	 * Atualiza o grid com a matriz utiliza pelo backtracking
	 */
	void UpdateGridView();

	/**
	 * M�todo utilizado para preencher a matriz auxiliar
	 */
	void FillGrixAux();

	/**
	 * Verifica se a jogada � valida, considerando o quadrante, linha e coluna
	 * @param		row		Recebe um int com a linha
	 * @param		col		Recebe um int com a coluna
	 * @param		num		Recebe o valor a ser testado
	 * @return				Retorna true se a jogada for v�lida
	 */
	bool isValid(int row, int col, int num);

	/**
	 * Verifica se a jogada � valida em rela��o a linha
	 * @param		row		Recebe um int com a linha
	 * @param		col		Recebe um int com a coluna
	 * @param		num		Recebe o valor a ser testado
	 * @return				Retorna true se a jogada for v�lida
	 */
	bool isValidRow(int row, int col, int num);

	/**
	 * Verifica se a jogada � v�lida em rela��o a coluna
	 * @param		row		Recebe um int com a linha
	 * @param		col		Recebe um int com a coluna
	 * @param		num		Recebe o valor a ser testado
	 * @return				Retorna true se a jogada for v�lida
	 */
	bool isValidCol(int row, int col, int num);

	/**
	 * Verifica se a jogada � v�lida em rela��o ao quadrante
	 * @param		row		Recebe um int com a linha
	 * @param		col		Recebe um int com a coluna
	 * @param		num		Recebe o valor a ser testado
	 * @return				Retorna true se a jogada for v�lida
	 */
	bool isValidSquade(int row, int col, int num);

	/**
	 * Localiza o quadrante de uma posi��o no tabuleiro
	 * @param		row		Recebe um int com a linha
	 * @param		col		Recebe um int com a coluna
	 * @return				Retorna um vector com as posi��es de linha e coluna do quadrante
	 */
	std::vector< std::pair<int,int> > GetSquade(int row, int col);

	/**
	 * M�todo cria a arvore com a estrutura dos resultados
	 * ap�s o c�lculo da solu��o
	 */
	void CreateTreeSolve();

};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
