#!/bin/sh

./a.out > actual

diff actual expected
