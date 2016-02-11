//---------------------------------------------------------------------------

#ifndef BackTrackingH
#define BackTrackingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
#include <time.h>
//---------------------------------------------------------------------------

/**
 * Classe respons�vel pela cria��o do thread que executa o backtracking
 * utilizado apenas para permitir a visualiza��o do funcionamento
 * do algoritmo backtracking
 */

class TMainForm;

class TBackTracking : public TThread
{

private:

	int m_row;										//armazena a linha corrente da solu��o
	int m_col;										//armazena a coluna corrente da solu��o
	int m_time;										//armazena o tempo para a simula��o

	bool m_CreateTree;						//armazena se deve construir a arvore

	TMainForm * m_main;						//ponteiro para a interface principal
	UnicodeString m_msg;					//armazena a mensagem para a interface

	/**
	 * M�todo envia mensagem para a interface gr�fica
	 */
	void __fastcall SetMessage();

	/**
	 * M�todo seleciona a c�lula corrente da solu��o
	 * utiliza as variaveis m_col e m_row
	 */
	void __fastcall SelectCell();

	/**
	 * Preenche o grid da interface com os dados da solu��o
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
