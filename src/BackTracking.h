//---------------------------------------------------------------------------

#ifndef BackTrackingH
#define BackTrackingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
#include <time.h>
//---------------------------------------------------------------------------

/**
 * Classe responsável pela criação do thread que executa o backtracking
 * utilizado apenas para permitir a visualização do funcionamento
 * do algoritmo backtracking
 */

class TMainForm;

class TBackTracking : public TThread
{

private:

	int m_row;										//armazena a linha corrente da solução
	int m_col;										//armazena a coluna corrente da solução
	int m_time;										//armazena o tempo para a simulação

	bool m_CreateTree;						//armazena se deve construir a arvore

	TMainForm * m_main;						//ponteiro para a interface principal
	UnicodeString m_msg;					//armazena a mensagem para a interface

	/**
	 * Método envia mensagem para a interface gráfica
	 */
	void __fastcall SetMessage();

	/**
	 * Método seleciona a célula corrente da solução
	 * utiliza as variaveis m_col e m_row
	 */
	void __fastcall SelectCell();

	/**
	 * Preenche o grid da interface com os dados da solução
	 * calculada na matriz auxiliar
	 */
	void __fastcall UpdateGridView();

	void __fastcall GetCreateTree();

protected:

	void __fastcall Execute();

public:

	__fastcall TBackTracking(TMainForm * main, int time, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
