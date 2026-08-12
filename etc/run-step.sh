#!/bin/bash

sbatch              run.sh tuned-new-wsymv_u
sbatch -d singleton run.sh tuned-new-wsymv_l
sbatch -d singleton run.sh tuned-new-dsymv_u
sbatch -d singleton run.sh tuned-new-dsymv_l
sbatch -d singleton run.sh tuned-new-ssymv_u
sbatch -d singleton run.sh tuned-new-ssymv_l
sbatch -d singleton run.sh tuned-new-hsymv_u
sbatch -d singleton run.sh tuned-new-hsymv_l

sbatch -d singleton run.sh tuned-new-i128symv_u
sbatch -d singleton run.sh tuned-new-i128symv_l
sbatch -d singleton run.sh tuned-new-i64symv_u
sbatch -d singleton run.sh tuned-new-i64symv_l
sbatch -d singleton run.sh tuned-new-i32symv_u
sbatch -d singleton run.sh tuned-new-i32symv_l
sbatch -d singleton run.sh tuned-new-i16symv_u
sbatch -d singleton run.sh tuned-new-i16symv_l

sbatch -d singleton run.sh tuned-new-uhemv_u
sbatch -d singleton run.sh tuned-new-uhemv_l
sbatch -d singleton run.sh tuned-new-zhemv_u
sbatch -d singleton run.sh tuned-new-zhemv_l
sbatch -d singleton run.sh tuned-new-chemv_u
sbatch -d singleton run.sh tuned-new-chemv_l
sbatch -d singleton run.sh tuned-new-khemv_u
sbatch -d singleton run.sh tuned-new-khemv_l

sbatch -d singleton run.sh

