#include <iostream>
#include <set>
#include <thread>
#include <mutex>
#include <vector>

template<typename E>
std::set<E> naiveSetIntersection(const std::set<E>& first,
						 	 	 const std::set<E>& second,
								 const std::set<E>& third) {
	std::set<E> result;

	for (const E& el : first) {
		if (second.find(el) != second.end() and third.find(el) != third.end()) {
			result.insert(el);
		}
	}

	return result;
}

template<typename E>
std::set<E> onePassSetIntersection(const std::set<E>& first,
						 	 	 const std::set<E>& second,
								 const std::set<E>& third) {
	std::set<E> result;

	auto firstIterator  = first.cbegin();
	auto secondIterator = second.cbegin();
	auto thirdIterator  = third.cbegin();

	while (firstIterator != first.cend() and secondIterator != second.cend()
			and thirdIterator != third.cend()) {
		if (*firstIterator > *secondIterator) {
			++secondIterator;
			continue;
		}

		if (*firstIterator < *secondIterator) {
			++firstIterator;
			continue;
		}

		if (*firstIterator > *thirdIterator) {
			++thirdIterator;
			continue;
		}

		if (*firstIterator < *thirdIterator) {
			++firstIterator;
			continue;
		}

		result.insert(*firstIterator);
		++firstIterator;
		++secondIterator;
		++thirdIterator;
	}

	return result;
}

template<typename E>
std::set<E> naiveMultiThreadSetIntersection(const std::set<E>& first,
						 	 	 const std::set<E>& second,
								 const std::set<E>& third,
								 int threadAmount) {
	std::set<E> result;
	std::mutex iterator_mutex;
	std::mutex result_mutex;

	auto iterator = first.begin();

	std::vector<std::thread> threads;
	auto end = first.cend();

	for (int i = 0; i < threadAmount; ++i) {
		threads.emplace_back(
				std::thread([&result, &iterator_mutex, &result_mutex, &iterator, end, &second, &third](){
			while (true) {
				E el;
				{
					std::lock_guard<std::mutex> lg(iterator_mutex);
					if (iterator == end) {
						return;
					}
					el = *iterator;
					++iterator;
				}

				if (second.find(el) != second.end() and third.find(el) != third.end()) {
					std::lock_guard<std::mutex> lg(result_mutex);
					result.insert(el);
				}
			}

		}));
	}

	for (std::thread& t : threads) {
		t.join();
	}

	return result;
}


template<typename E>
std::set<E> partioningMultiThreadSetIntersection(const std::set<E>& first,
						 	 	 const std::set<E>& second,
								 const std::set<E>& third,
								 int threadAmount) {
	std::set<E> result;
	std::mutex result_mutex;

	auto start = first.begin();

	std::vector<std::thread> threads;
	auto end = start;
	std::advance(end, first.size() / threadAmount);

	for (int i = 0; i < threadAmount; ++i) {
		threads.emplace_back(
				std::thread([&result, &result_mutex, &second, &third](typename std::set<E>::iterator start,
																					 typename std::set<E>::iterator end){
			while (true) {
				if (start == end) {
					return;
				}
				E el = *start;
				++start;

				if (second.find(el) != second.end() and third.find(el) != third.end()) {
					std::lock_guard<std::mutex> lg(result_mutex);
					result.insert(el);
				}
			}

		}, start, end));
		start = end;
		if (i == threadAmount - 2) {
			end = first.end();
		} else {
			std::advance(end, first.size() / threadAmount);
		}
	}

	for (std::thread& t : threads) {
		t.join();
	}

	return result;
}

template<typename E>
std::set<E> valuePartioningMultiThreadSetIntersection(const std::set<E>& first,
						 	 	 const std::set<E>& second,
								 const std::set<E>& third,
								 int threadAmount) {
	std::set<E> result;
	std::mutex result_mutex;

	auto start = first.begin();

	std::vector<std::thread> threads;

	if (first.empty()) {
		return result;
	}
	E max_element = *(--first.end());

	for (int i = 0; i < threadAmount; ++i) {
		typename std::set<E>::iterator end;

		if (i == threadAmount - 1) {
			end = first.end();
		} else {
			end = first.lower_bound(max_element / threadAmount * (i + 1));
		}

		threads.emplace_back(
				std::thread([&result, &result_mutex, &second, &third](typename std::set<E>::iterator start,
																					 typename std::set<E>::iterator end){
			int i = 0;
			while (true) {
				if (start == end) {
					return;
				}
				E el = *start;
				++start;

				if (second.find(el) != second.end() and third.find(el) != third.end()) {
					std::lock_guard<std::mutex> lg(result_mutex);
					result.insert(el);
				}
			}

		}, start, end));

		start = end;
	}

	for (std::thread& t : threads) {
		t.join();
	}

	return result;
}


template<typename E>
std::set<E> onePassMultiThreadSetIntersection(const std::set<E>& first,
						 	 	 const std::set<E>& second,
								 const std::set<E>& third,
								 int threadAmount) {
	std::set<E> result;
	std::mutex result_mutex;
	std::vector<std::thread> threads;
	E first_max_element = *(--first.end());
	E second_max_element = *(--second.end());
	E third_max_element = *(--third.end());

	for (int i = 0; i < threadAmount; ++i) {
		auto firstIterator = first.lower_bound(first_max_element / threadAmount * i);
		auto firstIteratorEnd = first.lower_bound(first_max_element / threadAmount * (i + 1) + threadAmount);

		auto secondIterator = second.lower_bound(second_max_element / threadAmount * i);
		auto secondIteratorEnd = second.lower_bound(second_max_element / threadAmount * (i + 1) + threadAmount);

		auto thirdIterator = third.lower_bound(third_max_element / threadAmount * i);
		auto thirdIteratorEnd = third.lower_bound(third_max_element / threadAmount * (i + 1) + threadAmount);

		threads.emplace_back(
				std::thread([&result, &result_mutex](
						typename std::set<E>::iterator firstIterator, typename std::set<E>::iterator firstIteratorEnd,
						typename std::set<E>::iterator secondIterator, typename std::set<E>::iterator secondIteratorEnd,
						typename std::set<E>::iterator thirdIterator, typename std::set<E>::iterator thirdIteratorEnd) {
			while (firstIterator != firstIteratorEnd and secondIterator != secondIteratorEnd
					and thirdIterator != thirdIteratorEnd) {
				if (*firstIterator > *secondIterator) {
					++secondIterator;
					continue;
				}

				if (*firstIterator < *secondIterator) {
					++firstIterator;
					continue;
				}

				if (*firstIterator > *thirdIterator) {
					++thirdIterator;
					continue;
				}

				if (*firstIterator < *thirdIterator) {
					++firstIterator;
					continue;
				}

				{
					std::lock_guard<std::mutex> lg(result_mutex);
					result.insert(*firstIterator);
				}

				++firstIterator;
				++secondIterator;
				++thirdIterator;
			}
		}, firstIterator, firstIteratorEnd, secondIterator, secondIteratorEnd, thirdIterator, thirdIteratorEnd));
	}

	for (std::thread& t : threads) {
		t.join();
	}

	return result;
}
