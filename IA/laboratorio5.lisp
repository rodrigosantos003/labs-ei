;;;; laboratorio5.lisp
;;;; Ficha laboratorial sobre funcoes de alto nivel em Lisp
;;;; Autor: 


;;; Exercicio Introdutorio  - funcall + lambda
;;(remover-se #'(lambda (x) (= x 0)) '(1 2 0 2 0 4))
(defun remover-se(pred lista)
  (cond ((null lista) NIL) 
        ((funcall pred (car lista)) (remover-se pred (cdr lista)))
        (T (cons (car lista) (remover-se pred (cdr lista))))))


;;; Exercicios - Parametros de lambda
;;(media 1 2 34 )
;; 12.333333
(defun media(&rest numeros)
  (/ (apply #'+ numeros) (length numeros))
)

;; (coluna ((1 2 3) (4 5 6) (7 8 9)))
;; (1 4 7)
(defun coluna (m1)
  (mapcar #'(lambda (linha &aux (cabeca (car linha))) cabeca) m1)
)

;; (aplicar-simbolo 'mod  2 3)
;; 2
;; (aplicar-simbolo '*  2 3)
;; 6
(defun aplicar-simbolo (operador a b)
  (eval (list operador a b))
)


;;; Exercicio avaliacao de turmas de alunos

;; Teste: (turma-1)
;; (("Joao" "Silva" (12.5 15 8.5)) ("Ana" "Santos" (11.5 18 13.5)) ("Paulo" "Jorge" (6.5 10 7.5)) ("Elisabete" "Navarro" (12.5 15 8.5)) ("Mario" "Rodrigues" (12.5 15 8.5)))
(defun turma-1 ()
  '(("Joao" "Silva" (12.5 15 8.5)) ("Ana" "Santos" (11.5 18 13.5)) ("Paulo" "Jorge" (6.5 10 7.5)) ("Elisabete" "Navarro" (12.5 15 8.5)) ("Mario" "Rodrigues" (12.5 15 8.5)))
)

;; nome
(defun nome (aluno)
  (car aluno)
)

;; apelido
(defun apelido (aluno)
  (second aluno)
)

;; notas
(defun notas (aluno)
  (third aluno)
)

;; media-das-notas
;; Teste: (media-das-notas '(10 15 20))
;; 15
(defun media-das-notas (notas)
  (let ((numero-de-notas (length notas)))
  (cond ((> numero-de-notas 0) (/ (apply #' + notas) numero-de-notas))
        (t 0)
  ))
)

;; media-da-turma
;; (media-da-turma #'media-das-notas (turma-1))
;; 11.666666
(defun media-da-turma (media-funcao turma)
  (let ((numero-de-alunos (length turma)))
    (cond ((> numero-de-alunos 0)
           (let ((medias-dos-alunos (mapcar (lambda (aluno) (funcall media-funcao (third aluno))) turma)))
             (funcall media-funcao medias-dos-alunos)))
          (t 0))
   )
)

;; percentagem-de-aprovados
;; (percentagem-aprovados (turma-1))
;; 80.0
(defun percentagem-aprovados (turma)
  (let* ((total-alunos (length turma))
         (aprovados (length (remover-se
                             (lambda (nota) (< nota 9.5))
                             (mapcar (lambda (aluno) (media-das-notas (third aluno))) turma)))))
    (cond ((= total-alunos 0) 0)
          (t (/ (* aprovados 100.0) total-alunos))
     ))
)


;; lista-dos-aprovados
;; Teste: (lista-dos-aprovados (turma-1))
;; Teste avaliar-turma: (avaliar-turma 'lista-dos-aprovados (turma-1))
;; (("Joao" "Silva") ("Ana" "Santos") NIL ("Elisabete" "Navarro") ("Mario" "Rodrigues"))


;; todos-aprovadosp
;; (todos-aprovadosp (turma-1))
;; NIL
(defun todos-aprovadosp (turma)
  (cond ((= (percentagem-aprovados turma) 100) t)
        (t nil)
  )
)

;;avaliar-turma
;;(("Joao" "Silva" (12.5 15 8.5)) ("Ana" "Santos" (11.5 18 13.5)) NIL ("Elisabete" "Navarro" (12.5 15 8.5)) ("Mario" "Rodrigues" (12.5 15 8.5)))
;; (avaliar-turma (turma-1) 'media-da-turma)
;; 11.6666
;; (avaliar-turma (turma-1) 'percentagem-aprovados )
;; 80.0


;; existep
;; (existep "Joao" "Silva" (turma-1)
;; T


