# Dilbert: Patching Peano with Hilbert

This repository contains patches for the open-source
[Peano framework](http://www.peano-framework.org/). Peano represents
a spacetree grid, using Guiseppe Peano's
[space-filling curve](https://en.wikipedia.org/wiki/Space-filling_curve),
for solvers of differential equations. Peano is a space-time code for
various solver codes such as the [ExaHyPE](http://exahype.eu/) hyperbolic
PDE engine.

This repository contains various patches for Peano, allowing users to put
extra features in this software without going off the main development
branch. Sticking to patches instead of a git branch is neccessary as peano
uses Subversion for source management.

## Features (so far)

  * Turn assertions on/off at run-time instead compile-time. To enable
    this patch, just apply `patches/runtime-assertions.patch` in your
    Peano installation.

## How to use

Assume you have checked out Peano's source in some directory:

```
$ svn info
Path: .
Working Copy Root Path: /home/me/numrel/exahype/Engine-ExaHyPE/Peano
URL: svn://svn.code.sf.net/p/peano/code/trunk/src
Relative URL: ^/trunk/src
Repository Root: svn://svn.code.sf.net/p/peano/code
Repository UUID: aa977e5b-e928-4c84-aa66-c90e40304b12
Revision: 2762
Node Kind: directory
Schedule: normal
Last Changed Author: tobiasweinzierl
Last Changed Rev: 2762
Last Changed Date: 2017-07-01 20:03:48 +0200 (Sat, 01 Jul 2017)
```

Then go and clone `dilbert` into a subdirectory, so you end up with
something like:

```
.
├── dilbert
│   ├── copy-to-peano.sh
│   ├── create-a-patch.sh
│   ├── patches
│   ├── README.md
│   └── src
├── other stuff
├── even other stuff
├── peano
│   ├── CommunicationSpecification.cpp
│   ├── CommunicationSpecification.h
│   ├── CommunicationSpecification.o
│   ├── datatraversal
│   ├── geometry
│   ├── grid
│   ├── heap
│   ├── MappingSpecification.cpp
│   ├── MappingSpecification.h
│   ├── MappingSpecification.o
│   ├── parallel
│   ├── peano.cpp
│   ├── peano.h
│   ├── peano.o
│   ├── performanceanalysis
│   ├── stacks
│   ├── utils
│   └── version.h
├── peano.doxygen-configuration
├── src.doxys
└── tarch
    ├── Assertions.h
    ├── compiler
    ├── la
    ├── logging
    ├── multicore
    ├── parallel
    ├── plotter
    ├── services
    ├── tests
    └── timing
```

That is, `dilbert` is just another directory next to `peano` and `tarch`,
the two main directories of Peano. You now just can apply patches in this
main installation directory. Or use any script from this directory to
do that.

## The name

Instead of the Peano curve, you could also use the Hilbert curve. Or just
stick to the [Dilbert](https://en.wikipedia.org/wiki/Dilbert) curve.

![Programming environment](hilbert.png)

Source: http://dilbert.com/strip/2017-01-02
