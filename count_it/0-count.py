#!/usr/bin/python3
""" find number of times words occur in subreddit titles """
import requests


def make_dictionary(word_list, dic):
    """ make dictionary from word list """
    for word in word_list:
        dic[word] = 0


def count_words(subreddit, word_list, dic={}, after=None):
    """ count words from list in subreddit titles """
    if len(dic) == 0:
        make_dictionary(word_list, dic)
    try:
        u = 'https://api.reddit.com/r/{}/hot'.format(subreddit)
        h = {'User-Agent': 'test'}
        p = {'limit': 100}
        if after:
            p['after'] = after
        r = requests.get(u, headers=h, params=p, allow_redirects=False).json()
        posts = r.get('data').get('children')
        for x in posts:
            for word in word_list:
                if word.lower() in x.get('data').get('title').lower().split():
                    dic[word] += 1
        after = r.get('data').get('after')
        if after:
            return count_words(subreddit, word_list, dic, after)
        for k, v in sorted(dic.items(), key=lambda x: x[1], reverse=True):
            if v > 0:
                print('{}: {}'.format(k, v))

    except:
        return
