;Função que recebe um número e uma lista e verifica se o número está no intervalo dos números da lista
(defun entre-intervalo (num lst)
  (cond
   ((and (numberp num) (> num (first lst)) (< num (second lst))
         (format t "~d é maior que ~d e menor que ~d" num (first lst) (second lst)))
    (T (format t "~d não é um número entre ~d e ~d" num (first lst) (second lst)))
    ))
)

;Função que calcula o máximo de valor entre 3 números
(defun max-3 (num1 num2 num3)
  (cond ((and (>= num1 num2) (>= num1 num3)) num1)
        ((>= num2 num3) num2)
        (T num3)
  )
)

;Função que resto da divisão entre 2 números é igual ao valor passado por argumento
(defun restop (divid divis res)
  (cond ((= divis 0) NIL)
        ((= (mod divid divis) res) T)
        (T NIL)
   )
)

;Função que verifica se um aluno está aprovado
(defun aprovadop (notas)
  (cond ((and (>= (first notas) 9.5) (>= (fourth notas) 9.5)) T)
        ((>= (/ (+ (first notas) (second notas) (third notas) (fourth notas)) 4) 9.5) T)
        (T NIL)
  )
)


(defun nota-final (notas ponderacoes)
  (cond ((= (+ (first ponderacoes) (second ponderacoes) (third ponderacoes)) 100) 
                (/ (+ (* (first notas) (first ponderacoes)) (* (second notas) (second ponderacoes)) (* (third notas) (third ponderacoes))) 100))
        (T -1)
)
)

(defun produto-somas (nums1 nums2)
  (* (+ (first nums1) (first nums2)) (+ (second nums1) (second nums2)) (+ (third nums1) (third nums2)))
)

(defun junta-listas-tamanho-igual (lst1 lst2)
  (cond ((= (length lst1) (length lst2)) (append lst1 lst2))
        ((> (length lst1) (length lst2)) lst1)
        (T lst2)
   )
)

(defun dois-ultimos-elementos (lst)
  (cond ((or (null lst) (<= (length lst) 2)) NIL)
        (T (cons (first (reverse lst)) (second (reverse lst))))
   )
)

(defun palindromop (lst)
  (cond ((equal lst (reverse lst)) T)
        (T NIL)
  )
)

(defun criar-pares (lst1 lst2)
  (cond ((/= (length lst1) (length lst2)) NIL)
        (T (list (cons (first lst1) (first lst2)) (cons (second lst1) (second lst2)) (cons (third lst1) (third lst2))))
  )
)

(defun verifica-pares (lst)
  (cond ((/= (length lst) 4) NIL)
        (t (list (evenp (first lst))
                 (evenp (second lst))
                 (evenp (third lst))
                 (evenp (fourth lst))))
  )
)

(defun rodar (lst direcao)
  (cond ((/= (length lst) 4) NIL)
        ((equal direcao 'dir) (list (second lst) (third lst) (fourth lst) (first lst)))
        ((equal direcao 'esq) (list (fourth lst) (first lst) (second lst) (third lst)))
  )
)