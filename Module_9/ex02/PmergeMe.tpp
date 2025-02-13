#include "PmergeMe.hpp"

/**
 * @brief Crée des paires triées à partir d'un tableau d'éléments.
 * 
 * Cette fonction prend un tableau et le divise en paires.
 * Les paires sont triées par ordre croissant.
 * Si le tableau a un nombre impair d'éléments,
 * l'élément restant est stocké séparément dans un tableau `leftover`.
 * 
 * @param array Le tableau d'éléments à transformer en paires.
 * @param pair Le tableau dans lequel les paires triées seront ajoutées.
 * @param leftover Le tableau dans lequel l'élément restant (s'il y en a) sera ajouté.
 */
template <typename Container, typename Pairs,
	typename Leftovers> void PmergeMe::CreatePairs(Container &array,
	Pairs &pair, Leftovers &leftover)
{
	size_t	i;

	for (i = 0; i + 1 < array.size(); i += 2)
	{
		if (array[i] > array[i + 1])
			pair.push_back(std::make_pair(array[i + 1], array[i]));
		else
			pair.push_back(std::make_pair(array[i], array[i + 1]));
	}
	if (array.size() % 2 != 0)
		leftover.push_back(array[array.size() - 1]);
}

// Algorithm Ford-Johnson

/**
 * @brief Fusionne deux sous-tableaux triés dans un seul tableau trié.
 * 
 * Cette fonction prend un tableau `arr` et trois indices (`left`, `mid`, `right`) qui définissent deux sous-tableaux.
 * Elle fusionne ces deux sous-tableaux triés dans un seul tableau trié en les comparant élément par élément.
 * 
 * @param arr Le tableau d'origine qui contient les sous-tableaux à fusionner.
 * @param left L'indice de début du premier sous-tableau.
 * @param mid L'indice médian qui sépare les deux sous-tableaux.
 * @param right L'indice de fin du deuxième sous-tableau.
 */
template <typename Container> void PmergeMe::merge(Container &arr, size_t left,
	size_t mid, size_t right)
{
	size_t	i = 0, j = 0, k;

	Container leftPart(arr.begin() + left, arr.begin() + mid + 1);
	Container rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);
	i = 0, j = 0, k = left;
	while (i < leftPart.size() && j < rightPart.size())
	{
		if (leftPart[i] <= rightPart[j])
			arr[k++] = leftPart[i++];
		else
			arr[k++] = rightPart[j++];
	}
	while (i < leftPart.size())
		arr[k++] = leftPart[i++];
	while (j < rightPart.size())
		arr[k++] = rightPart[j++];
}

/**
 * @brief Applique l'algorithme de tri fusion de manière récursive.
 * 
 * Cette fonction divise récursivement le tableau en sous-tableaux de plus en plus petits, puis fusionne 
 * les sous-tableaux triés pour obtenir un tableau trié final.
 * 
 * @param arr Le tableau à trier.
 * @param left L'indice de début du tableau.
 * @param right L'indice de fin du tableau.
 */
template <typename Container> void PmergeMe::mergeSort(Container &arr,
	size_t left, size_t right)
{
	size_t	mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

/**
 * @brief Insère récursivement des éléments dans un tableau trié.
 *
 * Cette fonction prend un tableau trié `sortedArray` et un tableau `elements` et insère les éléments
 * de `elements` dans `sortedArray` de manière à maintenir l'ordre trié. La recherche de la position d'insertion
 * est effectuée à l'aide de `std::lower_bound`, et l'insertion est réalisée de manière récursive.
 *
 * @param sortedArray Le tableau trié dans lequel les éléments seront insérés.
 * @param elements Le tableau des éléments à insérer.
 * @param left L'indice de début du tableau d'éléments.
 * @param right L'indice de fin du tableau d'éléments.
 */
template <typename Container> void PmergeMe::insert_Jacobsthon_Recursif(Container &sortedArray,
	Container &elements, size_t left, size_t right)
{
	size_t	mid;

	if (left > right)
		return ;

	mid = left + (right - left) / 2;
	if (mid >= elements.size())
		return ;

	typename Container::iterator pos = std::lower_bound(sortedArray.begin(),
	sortedArray.end(), elements[mid]);

	sortedArray.insert(pos, elements[mid]);
	if (mid > left)
		insert_Jacobsthon_Recursif(sortedArray, elements, left, mid - 1);
	if (mid < right)
		insert_Jacobsthon_Recursif(sortedArray, elements, mid + 1, right);
}

template <typename Container, typename Pairs,
	typename Leftovers> void PmergeMe::Sort_Ford_Johnson(Container &array,
	Pairs &pairs, Leftovers &leftovers)
{
	if (array.size() <= 1)
	return ;

	Container	smallest;
	Container	largest;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		smallest.push_back(pairs[i].first);
		largest.push_back(pairs[i].second);
	}
	if (leftovers.size() > 0)
		smallest.push_back(leftovers[0]);
	mergeSort(largest, 0, largest.size() - 1);
	insert_Jacobsthon_Recursif(largest, smallest, 0, smallest.size() - 1);
	array = largest;
}
