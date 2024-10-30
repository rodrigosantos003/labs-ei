;;;; laboratorio2.lisp
;;;; Disciplina de IA
;;;; Ficha de Laborat�rio n�2
;;;; Autor: 

;;; Para Debug
;; soma-3
(defun soma-3 (a b c)
"Fun��o que faz a soma de 3 n�meros passados como argumento"
	(+ a b c)
)

;; soma-4
(defun soma-4 (a b c d)
"Fun��o que faz a soma de 4 n�meros passados como argumento"
	(+ a b c d)
)

;;; Exercicios sobre fun��es em Lisp (n�o recursivas)
;; notas-dos-alunos
(defun notas-dos-alunos ()
  '((15.5 15 8.25 13) (17.5 11 9 13.25) (11.75 0 0 16))
)

;; notas-do-primeiro-aluno
(defun notas-do-primeiro-aluno (notas-dos-alunos)
  (car notas-dos-alunos)
)

;; calcula-media-notas
(defun calcula-media-notas (notas)
  (/ (soma-4 (first notas) (second notas) (third notas) (fourth notas)) 4)
)

;; maior-nota-do-aluno
(defun maior-nota-do-aluno (notas)
  (max (first notas) (second notas) (third notas) (fourth notas))
)